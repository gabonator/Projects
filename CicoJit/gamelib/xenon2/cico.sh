arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/5.0.3/include/ -L/opt/homebrew/Cellar/capstone/5.0.3/lib -lcapstone.5 -o cicodis

#./cicodis $PWD/dos/XENON2.EXE -raw words 1000:0f6c 20 && exit 0
# fixapi
INDIRECTS=1000:6284,1000:758f,1000:655b,1000:4311,1000:4759,1000:37df,1000:0853,1000:0761,1000:70f1,1000:6eef
# fixindirect
INDIRECTS=$INDIRECTS,1000:0761,1000:0853,1000:0897,1000:08b9,1000:091f,1000:0ab7,1000:0f2b,1000:1f4d,1000:1fb4,1000:1ff3,1000:20f7,1000:213c,1000:21e9,1000:221a,1000:229b,1000:237e,1000:23ed,1000:246d,1000:250b,1000:25a8,1000:262d,1000:2697,1000:28b8,1000:28df,1000:37df,1000:3801,1000:3835,1000:3872,1000:3900,1000:3998,1000:399c,1000:39ee,1000:3a99,1000:3aa7,1000:3b55,1000:3b76,1000:3bdf,1000:4311,1000:4759,1000:69c8,1000:69d0,1000:6a0a,1000:6aad,1000:6ac7,1000:6bca,1000:6d22,1000:6e2c,1000:714d,1000:71dd,1000:72c4,1000:7520,1000:7569,1000:7dde,1000:7e87,1000:830c,1000:83bd,1000:85d0,1000:866d,1000:8745,1000:8783,1000:87d5,1000:88a9,1000:89ae,1000:8c3e
# sub_128df - OK
INDIRECTS=$INDIRECTS,1000:2ab2,1000:2aa4,1000:2a48,1000:2a66,1000:308c,1000:2aca,1000:2a6e,1000:3246,1000:2e84,1000:31b6,1000:2f08,1000:2f7c,1000:3126,1000:2d86,1000:2df0,1000:2d2a,1000:2b80,1000:2ac4,1000:2ad0
# custom
INDIRECTS=$INDIRECTS,1000:3360,1000:35ce,1000:714a,1000:72c4,1000:7520,1000:480b,1000:ebd0,1000:1e61,1000:3aa7,1000:714a,1000:08b9,1f29:0cb1,1000:3a39,1000:0f2b,1000:3998,1000:28df,1000:2a6e,1000:2ab2,1000:37ca,1000:6d22,1000:1f4d,1000:308c,1000:6a0a,1000:25a8,1000:3835,1000:39ee,1000:091f,1000:3a39,1000:3b76,1000:6aad,1000:6696,1000:66a6
INDIRECTS=$INDIRECTS,1f29:1716,1f29:5213,1f29:3220,1f29:1716,1f29:3220,1000:6ac7,1000:2ad0,1000:8e01,1000:28b8
# level 2
INDIRECTS=$INDIRECTS,1000:7f32,1000:8e01,1000:8ca7,1000:88a9,1000:19bc,1000:00a4,1000:4311,1000:03a8,1000:89ae,1000:8c3e,1000:7f79,1000:866d,1000:7dde,1000:80ca
# level 2 monster
INDIRECTS=$INDIRECTS,1000:8114,1000:8126,1000:80f5,1000:87d5,1000:8783
# level 3
INDIRECTS=$INDIRECTS,1000:7ce6,1000:7bef,1000:7ac4,1000:7e87,1000:85d0,1000:3b55,1000:830c,1000:8d18,1000:83bd,1000:84e1,1000:8c5f

APICALLS=1000:04f2

./cicodis $PWD/dos/XENON2.EXE -recursive -ctx -segofscomment -stackguard start \
  -indirect $APICALLS,$INDIRECTS,1000:ac01,1000:a1d2,1000:a656,1000:a613,1000:a5a4,\
1000:9db3,1000:a0e5,1000:a33f,1000:a3bf,1000:a40f,1000:abd3,1000:abd9,1000:abdf,1000:abf5,1000:abfb,\
1000:99fb,1000:9a03,1000:9a0b,1000:a689,1000:a7b4,\
1000:0761,1000:0f2b,1000:1ff3,1000:20f7,1000:213c,1000:21e9,1000:262d,1000:28df,1000:37df,1000:3801,1000:3872,1000:3900,1000:3998,1000:4311,1000:4759,1000:69d0,1000:6a0a,1000:6aad,1000:6e2c,1000:72c4,1000:7e87,1000:830c,1000:85d0,1000:866d,1000:88a9,1000:89ae,1000:a469,1000:a5a4,1000:a613,1000:a656,1000:a689,\
1000:9e32,1000:9e89,1000:9ea4,1000:9f7f,1000:a027,1000:a090,1000:9f7f,\
1000:9f1c,1000:9a2b,1000:ab25,1000:c78a,1000:a7df,1000:a8d4,1000:a978,1000:a9cf,1000:aa9e,\
1000:9c4f,1000:9cd6,1000:9cfb,1000:9d20,1000:aaff,1000:9d4d,\
1000:b613,1000:b899,1000:bdd5,1000:bf03,1000:bf28,1000:bf71,1000:bff4,1000:c05b,1000:c067,1000:c0be,1000:c61a,1000:b6eb,1000:bcab,1000:bcd3,1000:bd43,1000:bd46,1000:c6e5,1000:b80d,1000:c230,1000:c2d5,1000:c746,\
1000:b968,1000:b9e3,1000:ba0e,1000:ba27,1000:bad0,1000:bb77,1000:bbb8,1000:bbdc,1000:c3ea,1000:c575,1000:b930,1000:c4d8,1000:b8f8,1000:b9b3,1000:baab,1000:c555,1000:b98b,1000:dd7f,\
1000:d2f0,1000:de2f,1000:de71,1000:e1b0,1000:e3b3,1000:deb6,1000:df13,1000:df70,1000:df75,\
1000:d3fa,1000:e2bf,1000:dfe9,1000:e33a,1000:e097,1000:e106,1000:da23,1000:dab0,1000:dad2,1000:db82,1000:dca2,\
1000:0d3d,1000:da58,1000:db2b,1000:dcf5,1000:db6f,1000:dc88,\
1000:d1b9,1000:d5f9,1000:d615,1000:d61e,1000:d62c,1000:d74c,1000:d82a,1000:d798,1000:d89d,1000:d8f5,1000:d5dd \
  -jumptable 1000:07f5 1000:07fb 4 calldwords bp \
  -jumptable 1000:0dab 1000:0db1 4 calldwords bp \
  -jumptable 1000:0d67 1000:0d6d 4 calldwords bp \
  -jumptable 1000:0def 1000:0df5 4 calldwords bp \
  -jumptable 1000:0d89 1000:0d8f 4 calldwords bp \
  -jumptable 1000:0a15 1000:0a1b 4 calldwords bp \
  -jumptable 1000:0d23 1000:0d29 4 calldwords bp \
  -jumptable 1000:0839 1000:083f 4 calldwords bp \
  -jumptable 1000:0817 1000:081d 4 calldwords bp \
  -jumptable 1000:085b 1000:0861 4 calldwords bp \
  -jumptable 1000:087d 1000:0883 4 calldwords bp \
  -jumptable 1000:089f 1000:08a5 4 calldwords bp \
  -jumptable 1000:08c1 1000:08c7 4 calldwords bp \
  -jumptable 1000:0927 1000:092d 4 calldwords bp \
  -jumptable 1000:0949 1000:094f 4 calldwords bp \
  -jumptable 1000:096b 1000:0971 4 calldwords bp \
  -jumptable 1000:098d 1000:0993 4 calldwords bp \
  -jumptable 1000:09af 1000:09b5 4 calldwords bp \
  -jumptable 1000:09f3 1000:09f9 4 calldwords bp \
  -jumptable 1000:0a37 1000:0a3d 4 calldwords bp \
  -jumptable 1000:0a59 1000:0a5f 4 calldwords bp \
  -jumptable 1000:0a7b 1000:0a81 4 calldwords bp \
  -jumptable 1000:0a9d 1000:0aa3 4 calldwords bp \
  -jumptable 1000:0abf 1000:0ac5 4 calldwords bp \
  -jumptable 1000:0b03 1000:0b09 4 calldwords bp \
  -jumptable 1000:0b47 1000:0b4d 4 calldwords bp \
  -jumptable 1000:0b8b 1000:0b91 4 calldwords bp \
  -jumptable 1000:0bad 1000:0bb3 4 calldwords bp \
  -jumptable 1000:0bcf 1000:0bd5 4 calldwords bp \
  -jumptable 1000:0bf1 1000:0bf7 4 calldwords bp \
  -jumptable 1000:0c13 1000:0c19 4 calldwords bp \
  -jumptable 1000:0c35 1000:0c3b 4 calldwords bp \
  -jumptable 1000:0c57 1000:0c5d 4 calldwords bp \
  -jumptable 1000:0c79 1000:0c7f 4 calldwords bp \
  -jumptable 1000:0c9b 1000:0ca1 4 calldwords bp \
  -jumptable 1000:0cbd 1000:0cc3 4 calldwords bp \
  -jumptable 1000:0cdf 1000:0ce5 4 calldwords bp \
  -jumptable 1000:0dcd 1000:0dd3 4 calldwords bp \
  -jumptable 1000:0e11 1000:0e17 4 calldwords bp \
  -jumptable 1000:0e33 1000:0e39 4 calldwords bp \
  -jumptable 1000:0e55 1000:0e5b 4 calldwords bp \
  -jumptable 1000:0e77 1000:0e7d 4 calldwords bp \
  -jumptable 1000:0e99 1000:0e9f 4 calldwords bp \
  -jumptable 1000:0ebb 1000:0ec1 4 calldwords bp \
  -jumptable 1000:0d01 1000:0d07 4 calldwords bp \
  -jumptable 1000:0b25 1000:0b2b 4 calldwords bp \
  -jumptable 1000:0905 1000:090b 4 calldwords bp \
  -jumptable 1000:0d45 1000:0d4b 4 calldwords bp \
  -jumptable 1000:70f3 1000:70f8 1-10 jumpwords bx \
  -jumptable 1000:6ef1 1000:6ef6 1-10 jumpwords bx \
  -jumptable 1000:49a4 1000:49a9 6 jumpwords bx \
  -jumptable 1000:7f7d 1000:90fd 13 jumpwords bx \
  -jumptable 1000:80cc 1000:9109 7 jumpwords bx \
  -jumptable 1000:4f5a 2853:381a 1-25 callwords bx \
  -jumptable 1000:0fa9 1000:0fa8 1-5 callwordsbyofs none \
  -jumptable 1000:0f6d 1000:0f6c 1-5 callwordsbyofs none \
  -jumptable 1000:0f8b 1000:0f8a 1-5 callwordsbyofs none \
  -jumptable 1000:0fc7 1000:0fc6 1-5 callwordsbyofs none \
  -jumptable 1000:0fe5 1000:0fe4 1-5 callwordsbyofs none \
  -jumptable 1000:1003 1000:1002 1-5 callwordsbyofs none \
  -jumptable 1000:b8f3 1000:C95E 9 jumpwords bx \
  -jumptable 1000:c773 1000:cc42 7 jumpwords bx \
  -jumptable 1000:e477 1000:ebaa 9 jumpwords bx \
  -jumptable 1000:9dae 1000:ada5 7 jumpwords bx \
  -jumptable 1000:abce 1000:af77 6 jumpwords bx \
  -jumptable 1000:d0ec 1000:e72e 10 jumpwords bx \
  -labels sub_141b1,1000:41e2,1000:41fb \
  > xenon2.clean

cp xenon2.clean xenon2.cpp
patch xenon2.cpp xenon2.patch
rm cicodis
