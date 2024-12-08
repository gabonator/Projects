podman build -t cicotunneler.container .
podman stop cicotunneler.instance
podman rm cicotunneler.instance
podman run -d -p 8042:8042 --name cicotunneler.instance cicotunneler.container
