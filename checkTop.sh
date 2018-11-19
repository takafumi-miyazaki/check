#!/bin/bash
 
# Linuxの資源について調査するbashスクリプト
# 個別の調査スクリプトをまとめて実行する

./checkHW.sh
./checkCPUs.sh
./checkLinux.sh
./checkThreads.sh
echo "All scripts done"
echo "Please check output files"
