#!/bin/bash
echo 1000 1000
for(( i=0;i<1000;i++ ));do
    for(( j=0;j<1000;j++ ));do
        echo -n '.'
    done
    echo 
done
