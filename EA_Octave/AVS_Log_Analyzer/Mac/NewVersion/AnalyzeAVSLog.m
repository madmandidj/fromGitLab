%%function [recognizedCells, partialCells, unrecognizedCells, resultsWithTriggerID, resultsStats] = AnalyzeAVSLog (_fileNameString, _triggerWord, _noiseTotalNum, _distInNoiseNum, _trigInDistNum)
function [recognizedCells, partialCells, unrecognizedCells, duplicateCells, resultsWithTriggerID, resultsStats] = AnalyzeAVSLog (_fileNameString, _triggerWord, 
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
  
  [resultsHashMap, duplicateCells] = CreateResultsHashMap(recognizedCells, totalNumOfTriggers, detectionColumnNum);
  
  trimmedResults = TrimHashMap(resultsHashMap);
  
  resultsWithTriggerID = AddIDToResults(trimmedResults, _noiseTotalNum, _distInNoiseNum, _trigInDistNum);
  
  resultsStats = GenerateResultsStats(resultsWithTriggerID, _noiseTotalNum, _distInNoiseNum, _trigInDistNum);
  
endfunction