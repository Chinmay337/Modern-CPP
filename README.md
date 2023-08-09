```
███╗   ███╗ ██████╗ ██████╗ ███████╗██████╗ ███╗   ██╗     ██████╗██████╗ ██████╗
████╗ ████║██╔═══██╗██╔══██╗██╔════╝██╔══██╗████╗  ██║    ██╔════╝██╔══██╗██╔══██╗
██╔████╔██║██║   ██║██║  ██║█████╗  ██████╔╝██╔██╗ ██║    ██║     ██████╔╝██████╔╝
██║╚██╔╝██║██║   ██║██║  ██║██╔══╝  ██╔══██╗██║╚██╗██║    ██║     ██╔═══╝ ██╔═══╝
██║ ╚═╝ ██║╚██████╔╝██████╔╝███████╗██║  ██║██║ ╚████║    ╚██████╗██║     ██║
╚═╝     ╚═╝ ╚═════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝     ╚═════╝╚═╝     ╚═╝


```

# Modern C++

- Just a repo of good C++ code I write and find useful.

<br/>

- My environment

  - `g++ (GCC)`
  - `Ubuntu 20.04.2 LTS`
  - `Linux 5.8.0-53-generic x86_64`
  - Mostly `C++17` and `C++20`
  - Docker with `Ubuntu 20.04.2 LTS` and `g++ (GCC)` or `clang++ (LLVM)` for uniform build and deployments

<br/>

- Reference build and run

```bash
# Development
g++ -std=c++20 -o quicksort quicksort.cpp && ./quicksort

# Production
g++ -std=c++20 -O3 -o quicksort quicksort.cpp && ./quicksort
```

<br/>

- `huffmanEncoding.cpp` - implementation of Huffman Encoding in `C++20` using an `Unbalanced Binary Tree`, `std::map`, `std::priority_queue`, and `std::bitset`.
