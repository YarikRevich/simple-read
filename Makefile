OS = $(shell uname | tr A-Z a-z)
export PATH := $(abspath bin/):${PATH}
VERBOSE = 1

.PHONY: help
.DEFAULT_GOAL := help
help:
	@grep -h -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

.PHONY: build
build: ## build the project
	@cd src && mkdir build && cd build && qmake ../SimpleRead && make

UNAME := $(shell uname)

.PHONY: install
install: ## install the application
ifeq ($(UNAME), Darwin)
	@cp -r src/build/target/SimpleRead.app /Volumes/Data/Applications
endif
