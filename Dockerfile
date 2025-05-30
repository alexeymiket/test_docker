FROM ubuntu:22.04

RUN apt-get update && apt-get install -y clang

WORKDIR /app

COPY mylib.h .
COPY mylib.cpp .
COPY main.cpp .
COPY data.txt .

RUN clang++ -std=c++20 -fPIC -shared mylib.cpp -o libmylib.so
RUN clang++ -std=c++20 -L. -lmylib main.cpp -o main

ENV LD_LIBRARY_PATH=/app

CMD ["./main"]