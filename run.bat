docker build -t cpp-dev .
docker run -it -v "%cd%":/home/Github/cpp-4-finance cpp-dev