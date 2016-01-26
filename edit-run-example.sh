A="$1"; while true; do vim example${A}.c && make example${A} && ./example${A}; read fuck; done
