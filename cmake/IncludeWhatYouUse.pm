## no critic (ValuesAndExpressions::ProhibitMagicNumbers)
## no critic (Subroutines::RequireArgUnpacking)
package IncludeWhatYouUse;
use strict;
use warnings;
use parent qw(Exporter);
use English qw{-no_match_vars};
use IPC::Open3;
our (@EXPORT_OK, %EXPORT_TAGS);
BEGIN {
    @EXPORT_OK = qw(
            run_asyncronous
            get_io_files
            get_real_exe_and_params
            );  # symbols to export on request
    %EXPORT_TAGS = (all => [qw(
            run_asyncronous
            get_io_files
            get_real_exe_and_params
            )]);
}

sub run_asyncronous {
    # my $cmd = shift;
    # my (@cmd_params) = @_;
    my($wtr, $rdr, $err);
    use Symbol 'gensym'; $err = gensym;
    my $pid = open3($wtr, $rdr, $err,
            @_);
    waitpid $pid, 0;
    my $child_exit_status = $CHILD_ERROR >> 8;
    return $child_exit_status, $rdr, $err;
}

sub get_io_files {
    my $par_nr = 1;
    my ($input, $output);
    while( my $param = shift @_ ) {
        if($param eq '-c') {
            $input = shift @_;
        } elsif($param eq '-o') {
            $output = shift @_;
        }
    }
    return $input, $output;
}
sub get_real_exe_and_params {
    my $par_nr = 1;
    my ($real_exe, $real_params);
    while( my $param = shift @_ ) {
        ## no critic (ControlStructures::ProhibitCascadingIfElse)
        if($param =~ m/^--real-exe=.+$/msx) {
            $real_exe = substr $param, 11;
        } elsif($param =~ m/^--real-exe$/msx) {
            $real_exe = shift @_;
        } elsif($param =~ m/^--real-params=.+$/msx) {
            $real_params = substr $param, 14;
        } elsif($param =~ m/^--real-params$/msx) {
            $real_params = shift @_;
        }
    }
    my @exe_params = split qr/;/msx, $real_params//q{};
    return $real_exe, @exe_params;
}

1;

