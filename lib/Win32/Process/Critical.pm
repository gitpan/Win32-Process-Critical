package Win32::Process::Critical;

#use 5.010000;
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
our %EXPORT_TAGS = ( 'all' => [ qw(SetIsCritic SetNotCritic) ] );

our @EXPORT_OK = ( @{ $EXPORT_TAGS{'all'} } );

our @EXPORT = qw(SetIsCritic SetNotCritic);

our $VERSION = '1.02';

require XSLoader;
XSLoader::load('Win32::Process::Critical', $VERSION);

# Preloaded methods go here.

1;
__END__
# Below is stub documentation for your module. You'd better edit it!

=head1 NAME

Win32::Process::Critical - Prevent interupt by setting your program as critical progress

=head1 SYNOPSIS

  use Win32::Process::Critical;
  SetIsCritic(); #Privileges Needed
  #Do something here but DO NOT DIE HERE
  SetNotCritic();

=head1 DESCRIPTION

	Prevent interupt by setting your program as critical progress

=head2 EXPORT

	SetIsCritic()
	SetNotCritic()

=head1 SEE ALSO

	my Mail: L<rootkwok@cpan.org>
	Install Win32::Process::Critical with PPM:
	ppm install http://sites.google.com/site/lokchungk/mod/Win32-Process-Critical.ppd?attredirects=0

=head1 AUTHOR

Baggio, Kwok Lok Chung L<rootkwok@cpan.org>

=head1 COPYRIGHT AND LICENSE

Copyright (C) 2009 by Baggio Kwok Lok Chung

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself, either Perl version 5.10.0 or,
at your option, any later version of Perl 5 you may have available.


=cut
