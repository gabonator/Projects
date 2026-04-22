#!/bin/bash
# Validation script: builds the emulator, renders all test patches, verifies MD5 checksums.
# Usage: ./validate.sh
set -e

cd "$(dirname "$0")"

CONTENT="$(cd /Users/gabrielvalky/Documents/git/CleanRoom/jsfun4/installer/Nexus\ Content && pwd)"

echo "=== Rendering ==="
mkdir -p render_port

# Default preset
./nexus.elf "" "render_port/default.wav" 2>/dev/null

# All patches from test_patches.txt
FAIL=0
while IFS= read -r line; do
  [[ "$line" =~ ^#.*$ || -z "$line" ]] && continue
  fxp="$CONTENT/$line"
  name=$(basename "$line" .fxp)
  echo Processing ${name}
  if [ ! -f "$fxp" ]; then
    echo "NOT FOUND: $line"
    FAIL=1
    continue
  fi
  result=$(./nexus.elf "$fxp" "render_port/${name}.wav" 2>&1 | tee "render_port/${name}.txt" | tail -1)
  if [ "$result" != "Done." ]; then
    echo "RENDER FAIL: $name"
    FAIL=1
  fi
done < validate/patches.txt

echo "All presets rendered."
echo ""
echo "=== Verifying checksums ==="

PASS=0
TOTAL=0
while IFS=' ' read -r expected_md5 filename; do
  filepath="render_port/$filename"
  if [ ! -f "$filepath" ]; then
    echo "MISSING: $filename"
    FAIL=1
    continue
  fi
  actual_md5=$(md5 -q "$filepath" 2>/dev/null || md5sum "$filepath" | cut -d' ' -f1)
  TOTAL=$((TOTAL + 1))
  if [ "$actual_md5" = "$expected_md5" ]; then
    PASS=$((PASS + 1))
  else
    echo "MISMATCH: $filename (expected $expected_md5, got $actual_md5)"
    FAIL=1
  fi
done < validate/checksums.md5

echo ""
echo "$PASS/$TOTAL checksums passed."
if [ $FAIL -eq 1 ]; then
  echo "VALIDATION FAILED"
  exit 1
else
  echo "VALIDATION PASSED"
fi

#for f in render_port/*.wav; do
#  echo "$(md5 -q "$f")  $f"
#done
