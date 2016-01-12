# hmqc_COdec
 hmqc_COdec - hmqc using second channel for X pulses and decoupling with the
 option
 of decoupling 13CO and 15N during t1 (for use in doubly-enriched
 molecules)

 Copyright 2016 University of Oregon

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.

                                SUBMISSION FORM

Submitter:      George A. Gray, Varian
Date submitted: 1992-10-20
                1994-01-31 (minor correction in macro - Krish)

File name:      hmqc_COdec
Directory:      psglib
Description:    hmqc using second channel for X pulses and decoupling with the
		option of decoupling 13CO and 15N during t1 (for use in
		doubly-enriched molecules)

Related files:  maclib/hmqc_COdec, manual/hmqc_COdec, parlib/hmqc_COdec

Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     third rf channel
Known software version compatibility:   VNMR 4.1, 4.3
Known OS version compatibility:         n.a.
Special instructions for installation:

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/psglib  
     cd psglib  
     git checkout hmqc_COdec-v1.0


You may also download the archive directly from github at

    https://github.com/OpenVnmrJ/maclib/archive/hmqc_COdec-v1.0.zip

Read hmqc_COdec.README for installation instructions.

In most cases, move the contribution to /vnmr/userlib/psglib 
then use extract to install the contribution:  

    extract psglib/hmqc_COdec