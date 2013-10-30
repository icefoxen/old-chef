#!/bin/bash

# Runs as root on the server.
# Installs Chef and runs chef-solo

chef_binary=/usr/bin/chef-solo

if ! test -f "$chef_binary"; then
   export DEBIAN_FRONTEND=noninteractive
   aptitude update &&
   #apt-get -o Dpkg::Options::="--force-confnew" --force-yes -fuy dist-upgrade &&
   aptitude install -y chef
fi

"$chef_binary" -c solo.rb -j solo.json


