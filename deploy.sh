#!/bin/sh

# A script to run on a client which goes to the given
# server and runs install.sh on it.

host="${1:-icefox@localhost}"

# The host key might change when we make a new VM,
# so we remove the old host key from known_hosts.

ssh-keygen -R $"{host#*@}" 2> /dev/null

tar cj . | ssh -o 'StrictHostKeyChecking no' "$host" '
sudo rm -rf ~/chef &&
mkdir ~/chef &&
cd ~/chef &&
tar xj &&
sudo bash install.sh'

