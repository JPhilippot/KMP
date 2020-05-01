#!/usr/bin/gnuplot

set terminal png notransparent interlace truecolor enhanced nocrop font "arial,18" size 1600,1200

set title "Comparatif des algorithmes\n pour la recherche de séquences.\n"
set style data histograms
set xlabel "Langage"
set ylabel "Temps écoulé (en secondes)"
out = "result.png"
set output out
plot "./Results/all.data" using 2:xtic(1)

