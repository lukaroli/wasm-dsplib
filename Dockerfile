FROM ubuntu:22.04

ARG WASI_SDK_VER_MAJOR=20
ARG WASI_SDK_VER_MINOR=0
ARG WABT_VER=1.0.32

RUN apt-get update && \
	apt-get install -y --no-install-recommends \
        ca-certificates \
        python3 \
        python3-pip \
        wget \
		make \
	&& \
	rm -rf /var/lib/apt/lists/*

RUN wget https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-${WASI_SDK_VER_MAJOR}/wasi-sdk-${WASI_SDK_VER_MAJOR}.${WASI_SDK_VER_MINOR}-linux.tar.gz && \
    tar -xf wasi-sdk-${WASI_SDK_VER_MAJOR}.${WASI_SDK_VER_MINOR}-linux.tar.gz && \
    rm wasi-sdk-${WASI_SDK_VER_MAJOR}.${WASI_SDK_VER_MINOR}-linux.tar.gz && \
    mv wasi-sdk-${WASI_SDK_VER_MAJOR}.${WASI_SDK_VER_MINOR} /opt/wasi-sdk-${WASI_SDK_VER_MAJOR}.${WASI_SDK_VER_MINOR}

RUN wget https://github.com/WebAssembly/wabt/releases/download/${WABT_VER}/wabt-${WABT_VER}-ubuntu.tar.gz && \
    tar -xf wabt-${WABT_VER}-ubuntu.tar.gz && \
    rm wabt-${WABT_VER}-ubuntu.tar.gz && \
    mv wabt-${WABT_VER} /opt/wabt-${WABT_VER}

WORKDIR /wasm-dsplib

ENV WASI_SDK_HOME=$WASI_SDK_HOME:/opt/wasi-sdk-${WASI_SDK_VER_MAJOR}.${WASI_SDK_VER_MINOR}
ENV PATH=$PATH:/opt/wasi-sdk-${WASI_SDK_VER_MAJOR}.${WASI_SDK_VER_MINOR}/bin
ENV PATH=$PATH:/opt/wabt-${WABT_VER}/bin

COPY requirements.txt requirements.txt

RUN pip install --no-cache-dir --upgrade pip && \
    pip install --no-cache-dir -r requirements.txt && \
    rm requirements.txt

CMD ["bash"]




    
