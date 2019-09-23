#!/usr/bin/perl

open(DATA,"<test.txt") or die "Couldn't open the file";
while(<DATA>){
    print "$_\n";
}
close DATA;

open(DATA,">>test.txt")or die "Couldn't open the file";
say DATA "This text was appended";

open(DATA,"<test.txt") or die "Couldn't open the file";
while(<DATA>){
    print "$_\n";
}
close DATA;