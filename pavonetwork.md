# Introduction #

Since version 0.03, VirtualMIPS emulates cs8900a network card which you can use it to communicate with your host pc. You can mount your host pc's file into emulator using nfs or copying files into emulator using http/ftp protocol.

CAUTION: CS8900a network card emulation is not fully tested. I will design a new method to communicate between host and emulator which is more efficient than cs8900a network card emulation.


# Create TAP device #

Before using network in emulator, you need to use 'tunctl' command to create a tap device which VirtualMIPS uses to send and receive packet.

```
tunctl
```

It will create a tap device 'tap0'.
```
[root@kill-bill /]# tunctl 
Set 'tap0' persistent and owned by uid 0
```

If 'tunctl' command is not found in your computer, please install uml\_utilities first.

**Debian/Ubuntu
```
sudo apt-get install uml-utilities
```**

**Archlinux
```
sudo pacman -S user-mode-linux
sudo pacman -S uml_utilities
modprobe tun
```**


# Configure pavo emulation #

Change the pavo.conf in virtualmips-${version}/build to enable network card emulation.

```
cs8900_enable = 1
cs8900_iotype = "tap:tap0"  <- tap name can be changed according to your system. 
```

# Configure host pc tap device #

Set an IP address for tap device.

```
sudo ifconfig tap0 10.0.0.100    <-- in host
```

# Run pavo emulation #

When you entering emulator, configure the network card of emulator.

```
# ifconfig eth0 10.0.0.2     <--in emulator
```

Make sure that the IP address of emulator network card and tap device should be in a subnet.

Now you can ping host tap device from emulator or ping emulator network card from host.

In emulator:
```
# ping 10.0.0.100
PING 10.0.0.100 (10.0.0.100): 56 data bytes
64 bytes from 10.0.0.100: seq=0 ttl=64 time=20.000 ms
64 bytes from 10.0.0.100: seq=1 ttl=64 time=0.000 ms
64 bytes from 10.0.0.100: seq=2 ttl=64 time=0.000 ms
64 bytes from 10.0.0.100: seq=3 ttl=64 time=0.000 ms
64 bytes from 10.0.0.100: seq=4 ttl=64 time=0.000 ms

--- 10.0.0.100 ping statistics ---
5 packets transmitted, 5 packets received, 0% packet loss
round-trip min/avg/max = 0.000/4.000/20.000 ms
```

In host:
```
[root@kill-bill /]# ping 10.0.0.2
PING 10.0.0.2 (10.0.0.2) 56(84) bytes of data.
64 bytes from 10.0.0.2: icmp_seq=1 ttl=64 time=58.3 ms
64 bytes from 10.0.0.2: icmp_seq=2 ttl=64 time=6.25 ms
64 bytes from 10.0.0.2: icmp_seq=3 ttl=64 time=7.39 ms
64 bytes from 10.0.0.2: icmp_seq=4 ttl=64 time=7.76 ms
64 bytes from 10.0.0.2: icmp_seq=5 ttl=64 time=7.88 ms

--- 10.0.0.2 ping statistics ---
5 packets transmitted, 5 received, 0% packet loss, time 4000ms
rtt min/avg/max/mdev = 6.252/17.530/58.355/20.420 ms
```

# Using webserver to transfer file #

We can get a file from host using webserver. Please configure your web server before. I use lighttpd in my archlinux.

In emulator:
```
# cd /home/
# ls
# wget http://10.0.0.100/lxr/http/valid_html3.2.gif
Connecting to 10.0.0.100 (10.0.0.100:80)
valid_html3.2.gif    100% |*******************************|   230  --:--:-- ETA
# ls
valid_html3.2.gif
```

# Using nfs #

Configure nfs server in your pc before using nfs.
When mounting nfs in emulator, please use **tcp** because emulator is not quick enough to process the incoming packets and some pcackets may be dropped.

In emulator
```
# ifconfig eth0 10.0.0.2
# ping 10.0.0.100
PING 10.0.0.100 (10.0.0.100): 56 data bytes
64 bytes from 10.0.0.100: seq=0 ttl=64 time=30.000 ms

--- 10.0.0.100 ping statistics ---
1 packets transmitted, 1 packets received, 0% packet loss
round-trip min/avg/max = 30.000/30.000/30.000 ms
# mount -t nfs -o tcp 10.0.0.100:/nfs /mnt/nfs       
# cd /mnt/nfs
# ls
2                                   test4
busybox                             test7
jz-gcc4-glib236-src                 test9
jz-gcc4-glib236-src.tar.gz          test999999999999999999999999999999
test
# rm -rf test
# ls
2                                   test4
busybox                             test7
jz-gcc4-glib236-src                 test9
jz-gcc4-glib236-src.tar.gz          test999999999999999999999999999999
#
```


