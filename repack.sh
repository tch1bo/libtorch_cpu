#!/bin/bash

rm -rf compressed.zip compressed
mkdir ./compressed
cp -R ./include ./lib ./compressed
zip -r compressed.zip compressed
