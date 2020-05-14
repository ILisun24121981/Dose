description:logs.txt 
			1. important file for automatic update the personal reports from common reports due to
			it save name of last sorted common report and prevent previouse common reports to be sorted 
			again. If log.txt will be deleted Application will start sorting from first common report in 
			"folder to search unsorted reports". If Link for "folder to store logs" not set logs.txt will 
			be created in folder of Application.

description:settings.txt
			1.file to store main application settings
			sittings


CommonRawReport - Report containing all rows from all standard raw reports.

UpdateCommonRawReport (Button)	-	Takes "LastCommonReportUpdateTime" parameter from Log.txt file and update CommonRawReport.txt
					with new rows by scanning all standard raw reports from date/time of parameter value. 
					"LastCommonReportUpdate" parameter is updated every time CommonRawReport.txt update has finished.
					This report is a base of data for all other reports and need to be filled to form other reports. 