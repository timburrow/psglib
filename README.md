# tocsy1d
 tocsy1d - a pulse sequence to do 1D tocsy with water suppression and pulses
 coming from only the  obs.xmtr.. The selective inversion pulse is
 generated via a attn_shape_pulse pulse sequence element that ramps the
 programmable attenuator through half-gauss, hermite or gaussian shapes.

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
Date submitted: 1992-10-27
                1993-01-08 (corrected shaped pulse function name,
                            fixed sequence name in macro - r.k.)
                1994-01-31 (gate statement replaced; attn_shape_pulse
                            replaced with shape_pulse; xmtroff()
                            added at the end of spinlock - Krish)
                1994-12-21 (fixed minor omission, slightly cleaned
                            up syntax - r.k.)

File name:      tocsy1d.c
Directory:      psglib
Description:    a pulse sequence to do 1D tocsy with water suppression and
                pulses coming from only the  obs.xmtr.. The selective
                inversion pulse is generated via a attn_shape_pulse pulse
                sequence element that ramps the programmable attenuator
                through half-gauss, hermite or gaussian shapes.

Related files:  maclib/tocsy1d, manual/tocsy1d, parlib/tocsy1d


Existing VnmrJ / VNMR files which are superseded or
otherwise affected by this submission:  none
Hardware configuration limitations:     Requires linear amplifiers
Known software version compatibility:   VNMR 4.1, 4.3
Known OS version compatibility:         n.a.
Special instructions for installation:

**This software has not been tested on OpenVnmrJ. Use at your own risk.**

To install this user contribution:  
Download the repository from GitHub and checkout the tag of the contribution you want.
Typically tags end in the version (e.g. -v1.0)

     git clone https://github.com/OpenVnmrJ/psglib  
     cd psglib  
     git checkout tocsy1d-v1.0


You may also download the archive directly from github at

    https://github.com/OpenVnmrJ/maclib/archive/tocsy1d-v1.0.zip

Read tocsy1d.README for installation instructions.

In most cases, move the contribution to /vnmr/userlib/psglib 
then use extract to install the contribution:  

    extract psglib/tocsy1d