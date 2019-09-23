#!/usr/bin/perl

use DBI;
my $driver = "SQLite";
my $database = 'TESTDB';
my $dsn = "DBI:$driver:database=$database";
my $userid = 'testuser';
my $password = 'test123';
my $dbh = DBI->connect($dsn,$userid,$password) or die $DBI::errstr;
my $stmt = qq(CREATE TABLE COMPANY(ID INT PRIMARY KEY NOT NULL,NAME TEXT NOT NULL,AGE INT NOT NULL,ADDRESS CHAR[50], SALARY REAL););

my $rv = $dbh->do($stmt);

if($rv<0){
    print $DBI::errstr;
}
else{
    print "Table created successfully\n";
}

my $stmt = qq(INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)VALUES(322,'PAUdL',20,'CALIFORNIA',2000000.00));
my $rv = $dbh->do($stmt) or die $DBI::strerr;
my $stmt = qq(INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)VALUES(444,'Niraddddddv',18,'New York',300000000.00));
my $rv = $dbh->do($stmt) or die $DBI::strerr;

my $stmt = qq(SELECT id,name,address,salary from COMPANY;);
my $sth = $dbh->prepare($stmt);
my $rv = $sth->execute() or die $DBI::strerr;

while(my @row = $sth->fetchrow_array()){
    print "\nID = ".$row[0];
    print "\nNAME = ".$row[1];
    print "\nADDRESS = ".$row[2];
    print "\nSALARY = ".$row[3];
}
print "\nOperation Successfull";

my $stmt = "DROP TABLE COMPANY";
my $rv = $dbh->do($stmt) or die $DBI::strerr;

$dbh->disconnect();