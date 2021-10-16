#!/bin/bash
ifconfig | grep 'ether ' | awk '/ether/ {print $2}'