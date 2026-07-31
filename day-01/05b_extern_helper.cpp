// This file DEFINES the variable -- this is the one real storage location.
int sharedAcrossFiles = 42;

void bumpSharedValue() {
    sharedAcrossFiles += 10;
}
