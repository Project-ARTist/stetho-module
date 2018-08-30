# Stetho Module 

[![Gitter](https://badges.gitter.im/Project-ARTist/CodeLib.svg)](https://gitter.im/project-artist/Lobby?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=body_badge)

The stetho ARTist module is an instrumentation module that injects facebook's custom Android debug bridge called 
[stetho](https://facebook.github.io/stetho/) into arbitrary target applications. When the device is connected to a PC and adb debugging is enabled, 
you can inspect the files, databases and layouts of all running apps instrumented with this module. 
This is a proof-of-concept release, hence it is neither optimized for performance nor will it work in each and every 
situation. You are welcome to report any issues via GitHub and give feedback in our 
[Gitter chat](https://gitter.im/project-artist/).


## Build

Assuming you have already installed the [Module SDK](https://github.com/Project-ARTist/module-sdk-gen), you can build 
this project by simply invoking `make` on a commandline from within the project's root directory. It will create a zip 
file in the `out` folder that can be pushed to the device and imported via the 
[ArtistGui](https://github.com/Project-ARTist/ArtistGui) module management. 

## Contents

The module consist of two parts: The codelib that contains the actual logic for initializing the stetho library and the 
*optimization passes* for the ARTist compiler that inject calls to codelib methods.

While the code for the instrumentation passes can be found in the `src` folder, the codelib part resides in a second 
repository [here](https://github.com/Project-ARTist/stetho-codelib) and the resulting apk is (for now) committed as a part of this repository to be able to 
immediately build it after checkout. 


# ARTist - The Android Runtime Instrumentation and Security Toolkit

ARTist is a flexible open source instrumentation framework for Android's apps and Java middleware. It is based on the Android Runtime’s (ART) compiler and modifies code during on-device compilation. In contrast to existing instrumentation frameworks, it preserves the application's original signature and operates on the instruction level. 

ARTist can be deployed in two different ways: First, as a regular application using our [ArtistGui](https://github.com/Project-ARTist/ArtistGui) project that allows for non-invasive app instrumentation on rooted devices, or second, as a system compiler for custom ROMs where it can additionally instrument the system server (Package Manager Service, Activity Manager Service, ...) and the Android framework classes (```boot.oat```). It supports Android versions after (and including) Marshmallow 6.0. 

For detailed tutorials and more in-depth information on the ARTist ecosystem, have a look at our [official documentation](https://artist.cispa.saarland) and join our [Gitter chat](https://gitter.im/project-artist/Lobby).

## Current state: Beta

We recently entered the beta phase for Project ARTist and hence not everything will work perfectly out-of-the-box, yet. 
However, with the new documentation and module SDK, it is easier than ever to get involved and, e.g., write own modules. 
To keep up with the current progress, keep an eye on the GitHub repositories of ARTist, check for new blog posts at 
[https://artist.cispa.saarland](https://artist.cispa.saarland) and feel free to leave feedback in our 
[Gitter chat](https://gitter.im/project-artist/). 

## Contribution

We hope to create an active community of developers, researchers and users around Project ARTist and hence are happy about contributions and feedback of any kind. There are plenty of ways to get involved and help the project, such as testing and writing Modules, providing feedback on which functionality is key or missing, reporting bugs and other issues, or in general talk about your experiences. The team is actively monitoring [Gitter](https://gitter.im/project-artist/) and of course the repositories, and we are happy to get in touch and discuss. We do not have a full-fledged contribution guide, yet, but it will follow soon (see beta announcement above). 

## Academia

ARTist is based on a paper called **ARTist - The Android Runtime Instrumentation and Security Toolkit**, published at the 2nd IEEE European Symposium on Security and Privacy (EuroS&P'17). The full paper is available [here](https://artist.cispa.saarland/res/papers/ARTist.pdf). If you are citing ARTist in your research, please use the following bibliography entry:

```
@inproceedings{artist,
  title={ARTist: The Android runtime instrumentation and security toolkit},
  author={Backes, Michael and Bugiel, Sven and Schranz, Oliver and von Styp-Rekowsky, Philipp and Weisgerber, Sebastian},
  booktitle={2017 IEEE European Symposium on Security and Privacy (EuroS\&P)},
  pages={481--495},
  year={2017},
  organization={IEEE}
}
```

There is a follow-up paper where we utilized ARTist to cut out advertisement libraries from third-party applications, move the library to a dedicated app (own security principal) and reconnect both using a custom Binder IPC protocol, all while preserving visual fidelity by displaying the remote advertisements as floating views on top of the now ad-cleaned application. The full paper **The ART of App Compartmentalization: Compiler-based Library Privilege Separation on Stock Android**, as it was published at the 2017 ACM SIGSAC Conference on Computer and Communications Security (CCS'17), is available [here](https://artist.cispa.saarland/res/papers/CompARTist.pdf).


