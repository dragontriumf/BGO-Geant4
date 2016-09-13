#!/bin/bash

g++ -O3 $(root-config --cflags --libs) analysis.C -o analysis
