for file in j*
do
    mv "$file" "${file/#j/lcof\-}"
    # ${file/#j/lcof\-} means replace the pattern that starts at beginning of string
    # by https://stackoverflow.com/questions/2372719/using-sed-to-mass-rename-files
done