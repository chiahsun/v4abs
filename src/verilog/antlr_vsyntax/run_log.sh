make | ansifilter -H -o tmp.html
echo "<!-- Runned @ " >> ~/public_html/log/log.html
date >> ~/public_html/log/log.html
echo "-->" >> ~/public_html/log/log.html
cat tmp.html >> ~/public_html/log/log.html
rm tmp.html

