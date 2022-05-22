/**
 *  ==================================================
 *  SoftChalk LessonBuilder
 *  Copyright 2003-2007 SoftChalk LLC
 *  All Rights Reserved.
 *
 *  http://www.softchalk.com
 *  ==================================================
 *	File date: January 3, 2007
 */

 /*
  *************************************************************
  * non-scoring version for non-forced frames
  *************************************************************
  */

function answersWin(myFile, myID, winSpecs) {
	answersWindow = window.open(myFile, myID, winSpecs);
}

function activity_win_close() {
	window.opener = top;
	window.close();
}

function newWin(myFile, myID, winSpecs) {
	var act_id = myID.substring(3);
	if (q_done_a[act_id] && !show_restart_a[act_id]) {
		alert("This activity has been attempted.\nOnly one access is allowed.");
	}
	else {
		q_done_a[act_id] = true;
		activityWin = window.open(myFile, myID, winSpecs);
	}
}

function readit() {}

function cookit() {}
