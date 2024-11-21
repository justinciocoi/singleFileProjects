monday=$(date -v -$(($(date +%u)-1))d +%b%d)

friday=$(date -v +$((5-$(date +%u)))d +%b%d)

file=$1

mv $file ~/Documents/Work/Timesheets/"JustinCiocoi_"$monday"_"$friday".pdf"
