#!/bin/bash
 
# Linuxの資源について調査するbashスクリプト
# 調査結果を./configCPUs.txtに出力する
# 参考: https://yunabe.jp/docs/maximum_number_of_threads.html

# 出力ファイル名の定義
output="./configCPUs.txt"
# 出力ファイルの生成
touch $output

# cpuinfoをファイルに出力
echo "[cat /proc/cpuinfoの出力結果]" >> $output
cat /proc/cpuinfo >> $output
echo "" >> $output

# meminfoをファイルに出力
echo "[cat /proc/meminfoの出力結果]" >> $output
cat /proc/meminfo >> $output
echo "" >> $output


