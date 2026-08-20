# List all directories

DIRS := src/day-01-exercises src/day-02-exercises src/day-03-exercises src/day-04-exercises src/day-05-exercises src/day-06-exercises 

all:
	@for dir in $(DIRS); do $(MAKE) -C $$dir; done

clean:
	@for dir in $(DIRS); do $(MAKE) -C $$dir clean; done