podman build -t cicodemo:latest .
podman create --name cicodemo_container cicodemo:latest
podman cp cicodemo_container:/app/bin bin
podman cp cicodemo_container:/app/dos dos
podman rm cicodemo_container
