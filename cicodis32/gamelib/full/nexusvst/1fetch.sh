# copy nexus.dll and synsoemu.dll from ReFx nexus 2.4 from your installation folder

if [[ "$(md5sum input/Nexus.dll | awk '{print $1}')" != "2a0778490dfeffd905cdbdcf7a065bc6" ]]; then
    echo bad for Nexus.dll
    exit 1
fi
if [[ "$(md5sum input/SYNSOEMU.dll | awk '{print $1}')" != "7286412b479fe399bc94affb9a85ba55" ]]; then
    echo bad for SYNSOEMU.dll
    exit 1
fi

echo Good, you have the right set of dll files!