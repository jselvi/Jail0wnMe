**DEPRECATED! These scripts were developed in 2014 and they won't work in modern iOS devices. ARCHIVED.**

This repository is just a dump with the scripts that I used in order to change JailbreakMe 3.0 exploits into a weaponized exploit.

Your paths probably are different from those in the shell scripts, so please adapt them to your own system.

Basically, you need JailbreakMe 3.0 PDF. There are different PDF depending on the iOS version. You should find the one that would work for your target.
Once you have your PDF, you can do something like this:

```
$ python iOSExploit.py iPad_4.3.3_8J2-3.pdf payload_wget exploit.pdf
```

`payload_wget` is a valid Mach-O app running the weaponized feature.
Nowadays there are more payloads available, but at the moment I did this research, I had to code my own a few of them. They are included in this repository.

Demo: https://youtu.be/4vvlFnmNNK8?t=1m
