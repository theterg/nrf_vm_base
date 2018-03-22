nrfdev 
------

This is a proof of concept build automation for compiling nordic nRF code from a VM or the cloud.
When combined with a CI server, this makes it possible to automatically compile firmware and generate hex files and/or DFU images!
It can also be used to compile nRF firmware code from a consistent VM environment across platforms.

## Using this to provision a Linux machine

Here are some bash commands that will set up the toolchain and environment. These should be run **within the same environment that will be building the firmware images**:

``` bash
sudo apt-get update
sudo apt-get install -y build-essential libssl-dev libffi-dev python-dev
pip install --upgrade -r requirements.txt
ansible-playbook -i "localhost," -c local infra/tests.yml
```

See ```circle.yml``` for a sample script where CircleCI can be used to automatically build NRF code.

## Running this from within a VM (using Vagrant)

This is useful for testing the ansible scripts to ensure that the environment is set up correctly. These should be run **from a host PC that will virtualize the dev environment**

Step 1) Installation:

* Install virtualbox from [virtualbox.org](https://www.virtualbox.org/wiki/Downloads)
* Install vagrant from [Vagrantup](https://www.vagrantup.com/downloads.html)
* Install ansible
    * On ubuntu - ```apt-get install ansible``` is sufficient
    * On OSX, homebrew is probably easiest: ```brew ansible```
        * If you don't have homebrew, git it at [brew.sh](http://brew.sh/)
* If you'd like to USB Debug from within the VM, make sure you install the VirtualBox Extension Pack for your platform

Step 2)
``` vagrant plugin install virtualbox```

Step 2)
```echo "33.33.33.55 nrfdev" | sudo tee -a /etc/hosts```

Step 3)
Consider adding this to your ssh config:

```
host nrfdev
	User deploy
	HostName nrfdev
	ForwardAgent yes
```

Step 4)
cd into the ```infra/``` folder and execute ```vagrant up --provider=virtualbox```

Step 5)
execute ```ssh nrfdev``` to ssh into the environment

