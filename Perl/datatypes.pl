#!/usr/bin/perl

$Name = 'Nirav';
$Age = 20;
$SapId = 60004170073;

print "Name = $Name\n";
print "Age = $Age\n";
print "Sap Id = $SapId\n";

@subjects = ('COA','CG','OS');
print "Subjects:\n";
print "@subjects\n";
push @subjects,'Math';
push @subjects,'OSTL';
print "After Pushing\n";
print "@subjects\n";
$popped = pop @subjects;
print "Popped element = $popped\n";
print "After Popping:\n@subjects\n";
shift @subjects;
print "After Shifting:\n@subjects\n";
unshift @subjects,'AOA';
print "After unshifting:\n@subjects\n";

%data = ('Nirav',20,"Mayur",23,"Ritik",20,"Jemin",16);
use Data::Dumper;
print Dumper(\%data);
print "Nirav's age = $data{'Nirav'}\n";
$data{"Jack"} = 20;
print "After Updating:\n";
print Dumper(\%data);
