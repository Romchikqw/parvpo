FROM alpine:latest
RUN apk update && \
    apk add --no-cache g++ git

WORKDIR /app

RUN git clone https://github.com/Romchikqw/parvpo.git .

RUN g++ -o my_program main.cpp

CMD ["./my_program", ">", "/app/output.txt"]
