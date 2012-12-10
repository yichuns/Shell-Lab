
void unix_error(char *msg) /* unix-style error */
{
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(0);
}

void Close(int fd)
{
  int rc;

  if ((rc = close(fd)) < 0)
    unix_error("Close error");
}

int Setpgid(pid_t pid, pid_t pgid){
  int val;
  if ((val = setpgid(pid, pgid)) < 0)
    unix_error("Setpgid error");
  return val;
}


pid_t Fork (void){
  pid_t pid;

  if ((pid = fork()) < 0)
    unix_error("Fork error");
  return pid;
}

void Execve(const char *filename, char *const argv[], char *const envp[])
{
  if (execve(filename, argv, envp) < 0)
    unix_error("Execve error");
}


int Open(const char *pathname, int flags, mode_t mode)
{
  int rc;

  if ((rc = open(pathname, flags, mode))  < 0)
    unix_error("Open error");
  return rc;
}

void Sigprocmask(int how, const sigset_t *set, sigset_t *oldset)
{
  if (sigprocmask(how, set, oldset) < 0)
    unix_error("Sigprocmask error");
  return;
}

void Sigemptyset(sigset_t *set)
{
  if (sigemptyset(set) < 0)
    unix_error("Sigemptyset error");
  return;
}

void Sigaddset(sigset_t *set, int signum)
{
  if (sigaddset(set, signum) < 0)
    unix_error("Sigaddset error");
  return;
}

pid_t Waitpid(pid_t pid, int *iptr, int options)
{
  pid_t retpid;

  if ((retpid  = waitpid(pid, iptr, options)) < 0)
    unix_error("Waitpid error");
  return(retpid);
}

void Kill(pid_t pid, int signum)
{
  int rc;

  if ((rc = kill(pid, signum)) < 0)
    unix_error("Kill error");
}
