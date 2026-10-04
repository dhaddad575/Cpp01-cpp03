#!/bin/bash

EXEC="./replace"
PASSED=0
FAILED=0
TEST_DIR=$(mktemp -d)

trap 'rm -rf "$TEST_DIR"' EXIT

if [ ! -x "$EXEC" ]; then
    make
fi

check_result()
{
    NAME="$1"
    INPUT="$2"
    S1="$3"
    S2="$4"
    EXPECTED="$5"

    printf "%s" "$INPUT" > "$TEST_DIR/input.txt"
    printf "%s" "$EXPECTED" > "$TEST_DIR/expected.txt"

    "$EXEC" "$TEST_DIR/input.txt" "$S1" "$S2" > /dev/null 2>&1

    if cmp -s "$TEST_DIR/input.txt.replace" "$TEST_DIR/expected.txt"; then
        echo "[OK] $NAME"
        PASSED=$((PASSED + 1))
    else
        echo "[KO] $NAME"
        FAILED=$((FAILED + 1))
    fi
}

check_failure()
{
    NAME="$1"
    shift

    "$@" > /dev/null 2>&1

    if [ $? -ne 0 ]; then
        echo "[OK] $NAME"
        PASSED=$((PASSED + 1))
    else
        echo "[KO] $NAME"
        FAILED=$((FAILED + 1))
    fi
}

check_result \
    "Una coincidencia" \
    "hola mundo" \
    "hola" \
    "adios" \
    "adios mundo"

check_result \
    "Varias coincidencias" \
    "hola mundo, hola 42" \
    "hola" \
    "adios" \
    "adios mundo, adios 42"

check_result \
    "Cadena inexistente" \
    "hola mundo" \
    "perro" \
    "gato" \
    "hola mundo"

check_result \
    "Eliminar coincidencias" \
    "uno dos uno" \
    "uno" \
    "" \
    " dos "

check_result \
    "Coincidencias al principio y al final" \
    "abc---abc" \
    "abc" \
    "X" \
    "X---X"

check_result \
    "La sustitucion contiene la cadena buscada" \
    "a" \
    "a" \
    "aa" \
    "aa"

check_result \
    "Archivo vacio" \
    "" \
    "hola" \
    "adios" \
    ""

check_result \
    "Varias lineas" \
    $'hola\nmundo\nhola\n' \
    "hola" \
    "adios" \
    $'adios\nmundo\nadios\n'

printf "%s" "contenido" > "$TEST_DIR/input.txt"

check_failure \
    "Sin argumentos" \
    "$EXEC"

check_failure \
    "Archivo inexistente" \
    "$EXEC" "$TEST_DIR/no_existe.txt" "hola" "adios"

check_failure \
    "s1 vacio" \
    "$EXEC" "$TEST_DIR/input.txt" "" "adios"

echo
echo "Correctos: $PASSED"
echo "Fallidos:  $FAILED"

if [ "$FAILED" -ne 0 ]; then
    exit 1
fi

exit 0