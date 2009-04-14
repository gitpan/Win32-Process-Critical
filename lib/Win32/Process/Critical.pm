package Win32::Process::Critical;

use 5.010000;
use strict;
use warnings;

require Exporter;

our @ISA = qw(Exporter);

# Items to export into callers namespace by default. Note: do not export
# names by default without a very good reason. Use EXPORT_OK instead.
# Do not simply export all your public functions/methods/constants.

# This allows declaration	use Win32::Process::Critical ':all';
# If you do not need this, moving things directly into @EXPORT or @EXPORT_OK
# will save memory.
our %EXPORT_TAGS = ( 'all' => [ qw() ] );

our @EXPORT_OK = ( @{ $EXPORT_TAGS{'all'} } );

our @EXPORT = qw(Critic);

our $VERSION = '0.02';

require XSLoader;
XSLoader::load('Win32::Process::Critical', $VERSION);

# Preloaded methods go here.

1;
__END__
=head1 NAME

Win32::Process::Critical - Prevent interrupting by setting it as a Critical process

=head1 SYNOPSIS

  use Win32::Process::Critical;
  Critic(1);			#Set Current Process is Critical
  #do something you don't want people to interupt but DO NOT LET THIS PROGRAM DIE until shutdown.

=head1 DESCRIPTION

WARNINGS! IF THE PROCESS IS SET AS CRITICAL PROCESS,
DO NOT TERMINATE IT OR LET IT DIE.

If your process is important that you do not want
user to interrupt it, you can set it as a critical process.

=head1 SEE ALSO

=head1 AUTHOR

Baggio, Kwok Lok Chung L<mailto:rootkwok@cpan.org>

=head1 COPYRIGHT AND LICENSE

Copyright (C) 2009 by Baggio, Kwok Lok Chung

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself, either Perl version 5.10.0 or,
at your option, any later version of Perl 5 you may have available.


=cut
