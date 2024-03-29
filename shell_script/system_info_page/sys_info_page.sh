#!/bin/bash

# sys_info_page: Program to output a system information page

PROGNAME=$(basename $0)
TITLE="System Information Report For $HOSTNAME"
CURRENT_TIME=$(date +"%x %r %Z")
TIME_STAMP="Genrated $CURRENT_TIME, by $USER"

#definition of output functions

#outputs the system uptime
report_uptime () {
	cat <<- _EOF_

		<h2>System Uptime</h2>
		<pre>$(uptime)</pre>

		_EOF_
	return
}

#outputs the amount of disk free
report_disk_space () {
	cat <<- _EOF_

		<h2>Disk Space Utilization</h2>
		<pre>$(df -h)</pre>

		_EOF_
	return
}

#outputs the amount of space used by home directory
report_home_space () {
	if [[ $(id -u) -eq 0 ]]; then
		cat <<- _EOF_

			<h2>Home Space Utilization (All Users)</h2>
			<pre>$(du -sh /home/*)</pre>

			_EOF_

	else

		cat <<- _EOF_

			<h2>Home Space Utilization ($USER)</h2>
			<pre>$(du -sh $HOME)</pre>

			_EOF_

	fi
	return
}

#displays the help for this script
usage () {
	cat <<- _EOF_

		Usage: $PROGNAME [option]... [filename]
		displays system information of a computer in html format

		-h, --help		display this help

		-f, --filename		provide name of a file into which the output 
					should be written. Should be followed by filename.

		-i, --interactive	Prompts to enter filename into which output should be 
					written. Then checks if filename exists if it does,
					asks to overite it's content.

		Note: If no arguement is provided, will display output on standard output stream.
		      If a non valid arguement is provided displays this help.

		_EOF_

	return
}

#produces output of system information in html format
write_html_page () {
	cat <<- _EOF_
	
	<html>

		<head>
			<title>$TITLE</title>
		</head>

		<body>

			<h1>$TITLE</h1>
			<p>$TIME_STAMP</p>
			$(report_uptime)
			$(report_disk_space)
			$(report_home_space)

		</body>

	<html>

	_EOF_
	return
}

#End of function definition

# process command line options

interactive=
filename=

while [[ -n $1 ]]; do
	case $1 in

		-f | --file)		shift
					filename=$1
					;;

		-i | --interactive)	interactive=1
					;;

		-h | --help)		usage
					exit
					;;

		*)			usage >&2
					exit 1
					;;
					
	esac
	shift
done

#interactive mode

if [[ -n $interactive ]]; then
	while true; do
		read -p "Enter name of output file: " filename

		if [[ -e $filename ]]; then
			read -p "'$filename' exists. Overwrite ? [y/n/q] >"

			case $REPLY in
				Y | y)	break
					;;

				q | Q) echo "Program terminaed."
					exit
					;;

				*)	continue
					;;

			esac

		else
			break

		fi
	done
fi

#output html page

if [[ -n $filename ]]; then
	if touch $filename && [[ -f $filename ]]; then
		write_html_page > $filename
	else
		echo "$PRGNAME: cannot write file '$filename'" >&2
		exit 1
		
	fi

else
	write_html_page
fi

choice=

read -p "Open report page on default browser > " choice

if [[ -n $choice ]]; then
	case $choice in
		Y | y)	$(xdg-open $filename)
				break
				;;

		*)      exit
				;;

		esac
fi