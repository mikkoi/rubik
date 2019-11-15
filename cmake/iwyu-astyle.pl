#!/usr/bin/env perl
## no critic (Subroutines::RequireArgUnpacking)
## no critic (InputOutput::RequireCheckedSyscalls)
use strict;
use warnings;
use Carp;
use File::Basename qw{dirname};
use lib dirname __FILE__;
use IncludeWhatYouUse qw(:all);
sub main {
    ## no critic (InputOutput::RequireBriefOpen)
    # open my $logfile, q{>>} , __FILE__ . q{.log} or croak q{No can open};
    # my $date = localtime;
    # chomp $date;
    # printf {$logfile} "------------------------(%s)--------------\n\n", $date;
    # my $par_nr = 1;
    # foreach my $par (@_) {
        # printf {$logfile} "var (%u): '%s'.\n", $par_nr++, $par;
    # }
    my ($exe, @params) = get_real_exe_and_params(@_);
    my ($in_fn, $dummy) = get_io_files(@_);
    # print (join "\n", $exe, $in_fn, $out_fn, @params), "\n";
    my $out_fn = "${in_fn}.formatted";
    my ($r, $stdout, $stderr) = run_asyncronous($exe, '--formatted', '--style=google', "--stdin=$in_fn", "--stdout=${out_fn}");
    # printf {$logfile} "---------------------------\n\n";
    # close $logfile or croak q{Cannot close file};
    # print "r:$r\n";
    # if($r ne q{0}) {
    #     print {*STDERR} $stderr;
    #     return 1;
    # }
    # print $stdout; # This is file pointer!
    my $diff = `\\diff $in_fn $out_fn`;
    if(length $diff == 0) {
        unlink $out_fn;
    }
    if($stdout =~ m/Formatted\s+$in_fn/msx) {
        # print {*STDERR} `diff -u --color=always ${in_fn}.orig ${in_fn}`;
        # open my $logfile, q{>>} , __FILE__ . q{.log} or croak q{No can open};
        # print {$logfile} `diff -u --color=always ${in_fn}.orig ${in_fn}`;
    # close $logfile or croak q{Cannot close file};
        return 1;
    } else {
        return 0;
    }
}

exit main(@ARGV);

