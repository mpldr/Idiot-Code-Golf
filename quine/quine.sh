for f in *;do if [ -f "$f" ]&&[[ -n $(sed -n '/^for f in/p;q' "$f") ]];then cat "$f";fi;done
