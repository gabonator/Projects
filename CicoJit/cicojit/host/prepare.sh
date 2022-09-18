cd ..
mkdir goose
mkdir test
mkdir intermediate
(
  cd goose
  unzip ../host/goose.zip
)
cd build
./cicodis -o ../test/ ../goose/GOOSE.EXE start -recursive -lines


