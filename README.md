# DigiCron
Software and hardware for the DigiCron retro smartwatch.

Want to try out the software on your device? Just visit the [DigiCron Simulator](simulator)!

## Getting the code
You must clone this repo like this:

```bash
git clone --recurse-submodules https://github.com/devicefuture/digicron
```

This is because this repo contains submodules which are used as libraries for the firmware and simulator.

## Building
Before building for the first time, install dev dependencies:

```bash
./build.sh --install-dev
```

To build the firmware and upload it to the target device, run:

```bash
./build.sh --upload
```

To build the firmware and the simulator, run:

```bash
./build.sh --sim
```

Then to run the simulator locally, start a web server in this directory. Run the following to start the web server at [localhost:8000](http://localhost:8000):

```bash
python3 -m http.server
```

### Building the app demo
First install the required dependencies:

```bash
sudo apt install clang lld
```

Then run:

```bash
apptest/build.sh
```