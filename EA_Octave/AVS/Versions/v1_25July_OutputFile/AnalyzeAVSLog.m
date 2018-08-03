%%  DESCRIPTION: Parses and analyzes the AVS log. Log should be saved as .txt 
%%                file from:
%%                https://alexa.amazon.com/spa/index.html#settings/dialogs
%%  INPUT: 'fileNameString' is the name of the .txt file, e.g. "Alexa_log.txt"
%%          'triggerWord' is the trigger word, e.g. "alexa" 
%%  OUTPUT: 'resultTable' is the table of results produced. Column 1 contains 
%%            triggers and commands recognized by AVS, column 2 is the time of 
%%            recognition, column 3 is the device name, column 4 is the 
%%            expected command number, column 5 is the detected command number
%%  ERRORS: error thrown when unable to open fileNameString, or output file
%%  LAST MODIFIED: 24/07/2018

function resultTable = AnalyzeAVSLog (fileNameString, triggerWord)
  [fidRead, fidWrite] = OpenReadWriteFiles(fileNameString);
  rawTextCellArr = CreateTextCells(fidRead);
  lastTriggerCell = FindLastCell(rawTextCellArr);
  resultTable = CreateResults(rawTextCellArr, lastTriggerCell);
  resultTable = PostProcessResults(resultTable);
  WriteResultsToFile(fidWrite, resultTable);
  CloseReadWriteFiles(fidRead, fidWrite);
endfunction

%%%%%%%%%%%%%%%%%%
%% Local Functions
%%%%%%%%%%%%%%%%%%
function [fidRead, fidWrite] = OpenReadWriteFiles(fileNameString)
  fileResultName = strcat(fileNameString,"_result.rtf");
  fidRead = fopen(fileNameString);
  CheckOpenFileSuccess(fidRead);
  fidWrite = fopen(fileResultName, 'w');
  CheckOpenFileSuccess(fidWrite);
endfunction

function CloseReadWriteFiles(fidRead, fidWrite)
  fclose(fidRead);
  fclose(fidWrite);
endfunction

function CheckOpenFileSuccess(fileID)
  if (-1 == fileID)
    error("Failed to open file");
  endif
endfunction


