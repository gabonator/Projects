Ali tech stb (abcom cryptobox) protocol including RTSP video streaming to VLC
created by reverse engineering of G-MScreen application

allows: 
  - discovery of compatible devices (e.g. 600 HD mini)
  - get device identification
     [{
     "StbStatus":    1,
     "ProductName":    "600HD Mini",
     "SoftwareVersion":    "1.09.17769_patch",
     "SerialNumber":    "170428042664",
     "ChannelNum":    281,
     "MaxNumOfPrograms":    6100
     }]
  - get channel list
  - send remote control commands
  - get streaming url & keep stream alive


note:
  - mini600HD does not provide enough power to stream encrypted channels