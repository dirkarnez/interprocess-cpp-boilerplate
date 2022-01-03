interprocess-cpp-boilerplate
============================
Using [svebert/InterprocessMsg](https://github.com/svebert/InterprocessMsg)

### Notes
- This project DOES NOT use Clang, just `mingw64` (x86_64-8.1.0-release-posix-sjlj-rt_v6-rev0.7z, with threading)

### Boost setup
- follow [dirkarnez/boost-playground](https://github.com/dirkarnez/boost-playground)

### Usage
- `interprocess-cpp-boilerplate.exe ["listener" | "publisher"]`
### Outcome
- `listener` listens to `default` channel
  - `listener` only receives message after `publisher` executable started
