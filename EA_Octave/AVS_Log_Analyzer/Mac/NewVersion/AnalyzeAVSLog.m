function [result] = AnalyzeAVSLog (_fileNameString, _triggerWord, 
                        _noiseTotalNum, _distInNoiseNum, _trigInDistNum)
                        
  detectionColumnNum = 5;

  totalNumOfTriggers = _trigInDistNum * _distInNoiseNum * _noiseTotalNum;
                        
  strCells = CreateStringCellArray(_fileNameString);
  
  trigCells = CreateMultiRowTrigCellArray(strCells);
  
  verifCells = CreateSingleRowTrigCellArray(trigCells, _triggerWord);
  
  dateAndDeviceCells = CreateLogDateDeviceColumns(verifCells);
  
  flippedCells = FlipCellsUpDown(dateAndDeviceCells);
  
  expectedNumCells = CreateExpectedNumColumn(flippedCells);
  
  detectedNumCells = CreateDetectedNumColumn(expectedNumCells);
  
  [recognizedCells, partialCells, unrecognizedCells] = ProcessCells(detectedNumCells, detectionColumnNum);
  
  resultsHashMap = CreateResultsHashMap(recognizedCells, totalNumOfTriggers, detectionColumnNum);
  
  trimmedResults = TrimHashMap(resultsHashMap);
  
  resultsWithTriggerID = AddIDToResults(trimmedResults, _noiseTotalNum, _distInNoiseNum, _trigInDistNum);
  
  result = resultsWithTriggerID;
  
endfunction