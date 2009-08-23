package Win32::Process::Critical;

require Exporter;

our @ISA = qw(Exporter);
our @EXPORT = qw(SetIsCritic SetNotCritic);
our $VERSION = '1.02264';

require XSLoader;
XSLoader::load('Win32::Process::Critical', $VERSION);

Win32::Process::Critical::Import();
1;
__END__

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

	Demo.pl
	my Mail: <rootkwok <AT> cpan <DOT> org>

=head1 AUTHOR

Baggio, Kwok Lok Chung <rootkwok <AT> cpan <DOT> org>

=head1 COPYRIGHT AND LICENSE

Copyright (C) 2009 by Baggio Kwok Lok Chung

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself, either Perl version 5.10.0 or,
at your option, any later version of Perl 5 you may have available.


=cut
