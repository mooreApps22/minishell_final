#include "../../inc/data.h"

void	config_child_sigquit(void);
void	config_child_sigint(void);
void	config_child_signals(struct termios *saved_termios);

void	config_child_sigquit(void)
{
	struct sigaction	sigquit;

	sigquit.sa_handler = SIG_DFL;
	sigquit.sa_flags = 0;
	sigemptyset(&sigquit.sa_mask);
	sigaction(SIGQUIT, &sigquit, NULL);
}

void	config_child_sigint(void)
{
	struct sigaction	sigint;
	
	sigint.sa_handler = SIG_DFL;
	sigint.sa_flags = 0;
	sigemptyset(&sigint.sa_mask);
	sigaction(SIGINT, &sigint, NULL);
}

void	config_child_signals(struct termios *saved_termios)
{
	tcsetattr(1, TCSAFLUSH, saved_termios);
	config_child_sigint();
	config_sigquit();
}
