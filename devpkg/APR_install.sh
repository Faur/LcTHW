set -e

# Get the source
cd /tmp
curl -L -O http://ftp.download-by.net/apache//apr/apr-1.5.2.tar.gz

# Extract and go into the source
tar -xzvf apr-1.5.2.tar.gz
cd apr-1.5.2

# configure, make, make install
./configure
make
sudo make install

# reset and cleanup
cd /tmp
rm -rf apr-1.5.2 apr-i.5.2.tar.gz


# Do the same with apr-util
curl -L -O http://ftp.download-by.net/apache//apr/apr-util-1.5.4.tar.gz

#Extract, move into
tar -xzvf apr-util-1.5.4.tar.gz
cd apr-util-1.5.4

# configure, make, make install
./configure --with-apr=/usr/local/apr
make
sudo make install

# clean up
cd /tmp
rm -rf apr-util-1.5.4* apr-1.5.2*




