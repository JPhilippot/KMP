#!/usr/bin/gnuplot

set terminal png notransparent interlace truecolor enhanced nocrop font "arial,18" size 1600,1200

set title "Comparatif des algorithmes\n pour la recherche de séquences.\n"
set style data histograms
set xlabel "Langage"
set ylabel "Temps écoulé (en secondes)"
out = "result.png"
set output out
plot "./results.data" using 2:xtic(1)

# set key outside below height 2

# algos  = "KMP"
# nb_algos = words(algos)

# set yrange [0.00001:10]
# set ylabel "Temps (en sec.)"
# set ytics nomirror
# set logscale y
# set y2label "Mémoire (KB)"
# set y2range [0:6*1024]
# set y2tics 0,1024

# set key maxcols 2

# do for [o=0:3] {
#   png_file = sprintf("performances-O%d.png", o)
#   titre = "Performances des algorithmes\n"
#   titre = titre . " de recherche de séquences\n"
#   titre = titre . sprintf("(compilés avec l'option -O%d)", o)
#   files = ""
#   do for [i=1:nb_algos] {
#     files = files . sprintf(" res-%s-O%d.csv", word(algos, i), o)
#   }
#   set output png_file
#   set title titre
#   plot for [i=1:nb_algos] word(files,i) using 3:5 with lines title sprintf("Temps %s", word(algos, i)), \
#        for [i=1:nb_algos] word(files,i) using 3:8 with linespoints pointtype 6 pointsize 1 title sprintf("Mémoire %s", word(algos, i)) axes x1y2
# }
