# XMLTag
A simple XML wrapper class for reading and writing XML for C++


<table class="memberdecls">

<tbody>

<tr class="heading">

<td colspan="2">

## <a name="pub-methods"></a>Public Member Functions

</td>

</tr>

<tr class="memitem:a07b7b572924c89d1db43babe1186549e">

<td class="memItemRight" valign="bottom">[XMLTag](classXMLTag.html#a07b7b572924c89d1db43babe1186549e) ()</td>

</tr>

<tr class="memitem:a9b237be00020a99ce884c31375786560">

<td class="memItemRight" valign="bottom">[XMLTag](classXMLTag.html#a9b237be00020a99ce884c31375786560) (const [XMLTag](classXMLTag.html) &tag)</td>

</tr>

<tr class="memitem:a9b4ce2949388da7115747db4244d6332">

<td class="memItemRight" valign="bottom">[XMLTag](classXMLTag.html#a9b4ce2949388da7115747db4244d6332) ([XMLTag](classXMLTag.html) *pParent)</td>

</tr>

<tr class="memitem:a5a7448a382d37ae1f8b1e53a1536c25e">

<td class="memItemRight" valign="bottom">[XMLTag](classXMLTag.html#a5a7448a382d37ae1f8b1e53a1536c25e) (const char *szTagName, const char *szValue)</td>

</tr>

<tr class="memitem:a155b50e71dc71e9174de681a06307d72">

<td class="memItemRight" valign="bottom">[XMLTag](classXMLTag.html#a155b50e71dc71e9174de681a06307d72) (const char *szTagName, bool bValue)</td>

</tr>

<tr class="memitem:a06d4c7e7d1c04e2d81f592340ba2ae9d">

<td class="memItemRight" valign="bottom">[XMLTag](classXMLTag.html#a06d4c7e7d1c04e2d81f592340ba2ae9d) (const char *szTagName, int [intValue](classXMLTag.html#adf8a5b94085d94caffd8e2ac6f9ccd50))</td>

</tr>

<tr class="memitem:aa3e495579da8cb5108632de3f91ced9b">

<td class="memItemRight" valign="bottom">[XMLTag](classXMLTag.html#aa3e495579da8cb5108632de3f91ced9b) (const char *szTagName, unsigned int uintValue)</td>

</tr>

<tr class="memitem:aba42746b9a1afb48102927dade6b4b98">

<td class="memItemRight" valign="bottom">[XMLTag](classXMLTag.html#aba42746b9a1afb48102927dade6b4b98) (const char *szTagName, float [floatValue](classXMLTag.html#a724a3f0ac76f19dff3d358b0ad6cbfd8))</td>

</tr>

<tr class="memitem:a6ca10fbcba355ea0d9c575c9cbf36c0d">

<td class="memItemRight" valign="bottom">[XMLTag](classXMLTag.html#a6ca10fbcba355ea0d9c575c9cbf36c0d) (const char *szTagName, double doubleValue)</td>

</tr>

<tr class="memitem:a42668f01feefc6e0191348aa08f13b84">

<td class="memItemRight" valign="bottom">[XMLTag](classXMLTag.html#a42668f01feefc6e0191348aa08f13b84) (const char *szTagName)</td>

</tr>

<tr class="memitem:a9798eccc00847c1b34e3c7a4a819d649">

<td class="memItemRight" valign="bottom">[XMLTag](classXMLTag.html#a9798eccc00847c1b34e3c7a4a819d649) (std::string strTagName, std::string strValue="")</td>

</tr>

<tr class="memitem:a2d329848ea05b546c994bb2204ab349e">

<td class="memItemRight" valign="bottom">[~XMLTag](classXMLTag.html#a2d329848ea05b546c994bb2204ab349e) ()</td>

</tr>

<tr class="memitem:a89d6e565a1e3f0431d5ef045b78e66bb">

<td class="memItemLeft" align="right" valign="top">void </td>

<td class="memItemRight" valign="bottom">[clear](classXMLTag.html#a89d6e565a1e3f0431d5ef045b78e66bb) ()</td>

</tr>

<tr class="memitem:aa6a58dea096f497f7cac715d66ac0424">

<td class="memItemLeft" align="right" valign="top">void </td>

<td class="memItemRight" valign="bottom">[strictMode](classXMLTag.html#aa6a58dea096f497f7cac715d66ac0424) (bool bMode)</td>

</tr>

<tr class="memitem:adab99b26b6d5687e32182367f8e11aa3">

<td class="memItemLeft" align="right" valign="top">void </td>

<td class="memItemRight" valign="bottom">[ignoreCase](classXMLTag.html#adab99b26b6d5687e32182367f8e11aa3) (bool bIgnore=false)</td>

</tr>

<tr class="memitem:ab0da977fa0d937a402299a77c2d70b22">

<td class="memItemLeft" align="right" valign="top">bool </td>

<td class="memItemRight" valign="bottom">[load](classXMLTag.html#ab0da977fa0d937a402299a77c2d70b22) (const char *szFileName)</td>

</tr>

<tr class="memitem:a4f28e36b5c33620f60e5c513b5fb9c09">

<td class="memItemLeft" align="right" valign="top">bool </td>

<td class="memItemRight" valign="bottom">[store](classXMLTag.html#a4f28e36b5c33620f60e5c513b5fb9c09) (const char *szFileName, bool bFormatted=false)</td>

</tr>

<tr class="memitem:a66a342b912dd779f6afb5147cbf25073">

<td class="memItemLeft" align="right" valign="top">int </td>

<td class="memItemRight" valign="bottom">[read](classXMLTag.html#a66a342b912dd779f6afb5147cbf25073) (const char *pBuffer, int iBufferSize=0)</td>

</tr>

<tr class="memitem:ae4b23a62c94695a547b0efd975d75b4d">

<td class="memItemLeft" align="right" valign="top">bool </td>

<td class="memItemRight" valign="bottom">[read](classXMLTag.html#ae4b23a62c94695a547b0efd975d75b4d) (FILE *fp)</td>

</tr>

<tr class="memitem:a718b299712d12f38592bae89c52b9970">

<td class="memItemLeft" align="right" valign="top">int </td>

<td class="memItemRight" valign="bottom">[write](classXMLTag.html#a718b299712d12f38592bae89c52b9970) (FILE *fp) const</td>

</tr>

<tr class="memitem:a135670a13b5edc97e0938a17bccd7cd9">

<td class="memItemLeft" align="right" valign="top">int </td>

<td class="memItemRight" valign="bottom">[write](classXMLTag.html#a135670a13b5edc97e0938a17bccd7cd9) (char **pBuffer) const</td>

</tr>

<tr class="memitem:a5f6f0a8ce4b6ed80aa45d5d02c3d28a6">

<td class="memItemLeft" align="right" valign="top">const char * </td>

<td class="memItemRight" valign="bottom">[getXML](classXMLTag.html#a5f6f0a8ce4b6ed80aa45d5d02c3d28a6) () const</td>

</tr>

<tr class="memitem:ab435f16a4863605952d447f000e8e551">

<td class="memItemLeft" align="right" valign="top">const char * </td>

<td class="memItemRight" valign="bottom">[getXMLFormatted](classXMLTag.html#ab435f16a4863605952d447f000e8e551) () const</td>

</tr>

<tr class="memitem:a122a7d4eac94eeab7eb7722ecb283b88">

<td class="memItemLeft" align="right" valign="top">[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">[operator=](classXMLTag.html#a122a7d4eac94eeab7eb7722ecb283b88) (const char *szComp)</td>

</tr>

<tr class="memitem:a24fed9521a79d4047d8aa658196e02aa">

<td class="memItemLeft" align="right" valign="top">[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">[operator=](classXMLTag.html#a24fed9521a79d4047d8aa658196e02aa) (const [XMLTag](classXMLTag.html) &tag)</td>

</tr>

<tr class="memitem:a25d6027ae84f0fba22aaea88c92cc21f">

<td class="memItemLeft" align="right" valign="top">bool </td>

<td class="memItemRight" valign="bottom">[operator==](classXMLTag.html#a25d6027ae84f0fba22aaea88c92cc21f) (const char *szComp)</td>

</tr>

<tr class="memitem:ae6e264eb5e01b4db6a688a9eeb90a257">

<td class="memItemLeft" align="right" valign="top">bool </td>

<td class="memItemRight" valign="bottom">[operator!=](classXMLTag.html#ae6e264eb5e01b4db6a688a9eeb90a257) (const char *szComp)</td>

</tr>

<tr class="memitem:a6400cc4f6932df2245f036db79922004">

<td class="memItemLeft" align="right" valign="top">bool </td>

<td class="memItemRight" valign="bottom">[operator==](classXMLTag.html#a6400cc4f6932df2245f036db79922004) (const [XMLTag](classXMLTag.html) &tag) const</td>

</tr>

<tr class="memitem:ac7c420994cfbd7c7774446c52a43d909">

<td class="memItemLeft" align="right" valign="top">bool </td>

<td class="memItemRight" valign="bottom">[operator!=](classXMLTag.html#ac7c420994cfbd7c7774446c52a43d909) ([XMLTag](classXMLTag.html) &tag)</td>

</tr>

<tr class="memitem:abc5bb4a3418883769b75fc6b8fac1b69">

<td class="memItemLeft" align="right" valign="top">const std::string </td>

<td class="memItemRight" valign="bottom">[path](classXMLTag.html#abc5bb4a3418883769b75fc6b8fac1b69) () const</td>

</tr>

<tr class="memitem:ada73a34c65c85a2d271b11c73ce98ffa">

<td class="memItemLeft" align="right" valign="top">[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">[path](classXMLTag.html#ada73a34c65c85a2d271b11c73ce98ffa) (const std::string strTagPath, std::vector< int >vecVals)</td>

</tr>

<tr class="memitem:aba83691a33252ae5338d4ad649396146">

<td class="memItemLeft" align="right" valign="top">[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">[path](classXMLTag.html#aba83691a33252ae5338d4ad649396146) (const std::string strTagPath,...)</td>

</tr>

<tr class="memitem:a37cca22a82e36cc5c62ca78a159b3d58">

<td class="memItemLeft" align="right" valign="top">bool </td>

<td class="memItemRight" valign="bottom">[hasPath](classXMLTag.html#a37cca22a82e36cc5c62ca78a159b3d58) (const std::string strTagPath,...)</td>

</tr>

<tr class="memitem:a3c5a59da18f60c57c225695ca918cb08">

<td class="memItemLeft" align="right" valign="top">[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">[buildPath](classXMLTag.html#a3c5a59da18f60c57c225695ca918cb08) (const std::string strTagPath,...)</td>

</tr>

<tr class="memitem:a0ff5ddde734f9f2bc3650cd261b0a788">

<td class="memItemLeft" align="right" valign="top"><a class="anchor" id="a0ff5ddde734f9f2bc3650cd261b0a788"></a>[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">**addPath** (const std::string strTagPath,...)</td>

</tr>

<tr class="memitem:a65bbf831deac7cce44a3dc40d1487413">

<td class="memItemLeft" align="right" valign="top">[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">[operator[]](classXMLTag.html#a65bbf831deac7cce44a3dc40d1487413) (const std::string strTagName) const</td>

</tr>

<tr class="memitem:a0b7f3b781d80c25e04adc4d95591bb4d">

<td class="memItemLeft" align="right" valign="top">[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">[operator[]](classXMLTag.html#a0b7f3b781d80c25e04adc4d95591bb4d) (const char *szTagName) const</td>

</tr>

<tr class="memitem:a50aa848ed46ae7fb8d6bd8238fe59139">

<td class="memItemLeft" align="right" valign="top"><a class="anchor" id="a50aa848ed46ae7fb8d6bd8238fe59139"></a>[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">**getTag** (const std::string strTagName)</td>

</tr>

<tr class="memitem:a3e1ad572db59121b26dc5e3dc842b619">

<td class="memItemLeft" align="right" valign="top"><a class="anchor" id="a3e1ad572db59121b26dc5e3dc842b619"></a>[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">**getTag** (const char *szTagName)</td>

</tr>

<tr class="memitem:a4530706e668da47085b454d6402bc190">

<td class="memItemLeft" align="right" valign="top">[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">[operator[]](classXMLTag.html#a4530706e668da47085b454d6402bc190) (size_t iTagIndex) const</td>

</tr>

<tr class="memitem:a4dd20b63b3596378491d09c9a2cf779e">

<td class="memItemLeft" align="right" valign="top"><a class="anchor" id="a4dd20b63b3596378491d09c9a2cf779e"></a>[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">**getTag** (size_t iTagIndex)</td>

</tr>

<tr class="memitem:aef2014a418d40d88ce2751f2badaec42">

<td class="memItemLeft" align="right" valign="top">[XMLTag](classXMLTag.html) * </td>

<td class="memItemRight" valign="bottom">[parent](classXMLTag.html#aef2014a418d40d88ce2751f2badaec42) ()</td>

</tr>

<tr class="memitem:ab9701b23aadda012638dee320f9372f0">

<td class="memItemLeft" align="right" valign="top">const char * </td>

<td class="memItemRight" valign="bottom">[buffer](classXMLTag.html#ab9701b23aadda012638dee320f9372f0) ()</td>

</tr>

<tr class="memitem:a937640876c42ca652f488336d1b1b30b">

<td class="memItemLeft" align="right" valign="top">int </td>

<td class="memItemRight" valign="bottom">[buffer_size](classXMLTag.html#a937640876c42ca652f488336d1b1b30b) ()</td>

</tr>

<tr class="memitem:a4c71240412e01900fd89453ace812350">

<td class="memItemLeft" align="right" valign="top">int </td>

<td class="memItemRight" valign="bottom">[count](classXMLTag.html#a4c71240412e01900fd89453ace812350) () const</td>

</tr>

<tr class="memitem:aedf362ddaed5f3fac2f6686ccc742913">

<td class="memItemLeft" align="right" valign="top">int </td>

<td class="memItemRight" valign="bottom">[attribute_count](classXMLTag.html#aedf362ddaed5f3fac2f6686ccc742913) () const</td>

</tr>

<tr class="memitem:a17ff3c7cfda65706f7b3655f68a2ddda">

<td class="memItemLeft" align="right" valign="top">[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">[addXML](classXMLTag.html#a17ff3c7cfda65706f7b3655f68a2ddda) (std::string strXML)</td>

</tr>

<tr class="memitem:a41dcf7fe1eb3058bd81930233dee8d28">

<td class="memItemLeft" align="right" valign="top">[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">[addTag](classXMLTag.html#a41dcf7fe1eb3058bd81930233dee8d28) ([XMLTag](classXMLTag.html) *pTag)</td>

</tr>

<tr class="memitem:ac284b24a802583ac9ceb358125e178bf">

<td class="memItemLeft" align="right" valign="top">[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">[addTag](classXMLTag.html#ac284b24a802583ac9ceb358125e178bf) ([XMLTag](classXMLTag.html) &Tag)</td>

</tr>

<tr class="memitem:a2bb81bc008ea18c0a4a6606a824133eb">

<td class="memItemLeft" align="right" valign="top">[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">[addTag](classXMLTag.html#a2bb81bc008ea18c0a4a6606a824133eb) (const char *szName)</td>

</tr>

<tr class="memitem:a972545b8238d250185c7552f9285a592">

<td class="memItemLeft" align="right" valign="top">[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">[addTag](classXMLTag.html#a972545b8238d250185c7552f9285a592) (const char *szName, const char *szValue)</td>

</tr>

<tr class="memitem:aec264a9f4306d5b90c097c7f1d088283">

<td class="memItemLeft" align="right" valign="top">[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">[addTag](classXMLTag.html#aec264a9f4306d5b90c097c7f1d088283) (const char *szName, bool bValue)</td>

</tr>

<tr class="memitem:a836724f95250e0e46cb1c4900aebf655">

<td class="memItemLeft" align="right" valign="top">[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">[addTag](classXMLTag.html#a836724f95250e0e46cb1c4900aebf655) (const char *szName, int [intValue](classXMLTag.html#adf8a5b94085d94caffd8e2ac6f9ccd50))</td>

</tr>

<tr class="memitem:a4c7ee78fd9f69fa4d617eee81538f174">

<td class="memItemLeft" align="right" valign="top">[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">[addTag](classXMLTag.html#a4c7ee78fd9f69fa4d617eee81538f174) (const char *szName, unsigned int uintValue)</td>

</tr>

<tr class="memitem:ab114ea4189652208334bdbf803494e6c">

<td class="memItemLeft" align="right" valign="top">[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">[addTag](classXMLTag.html#ab114ea4189652208334bdbf803494e6c) (const char *szName, float [floatValue](classXMLTag.html#a724a3f0ac76f19dff3d358b0ad6cbfd8))</td>

</tr>

<tr class="memitem:a06ed9de698dc3c7d9c6bfd5acdcddff0">

<td class="memItemLeft" align="right" valign="top">[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">[addTag](classXMLTag.html#a06ed9de698dc3c7d9c6bfd5acdcddff0) (const char *szName, double doubleValue)</td>

</tr>

<tr class="memitem:a24e64fb58c0aa2680a19dba6c2dacb7d">

<td class="memItemLeft" align="right" valign="top">[XMLTag](classXMLTag.html) & </td>

<td class="memItemRight" valign="bottom">[addTag](classXMLTag.html#a24e64fb58c0aa2680a19dba6c2dacb7d) (std::string strName, std::string strValue="")</td>

</tr>

<tr class="memitem:a60c9450d76565907814f6331875aeeaa">

<td class="memItemLeft" align="right" valign="top">void </td>

<td class="memItemRight" valign="bottom">[insertXML](classXMLTag.html#a60c9450d76565907814f6331875aeeaa) (std::string strXML)</td>

</tr>

<tr class="memitem:a97755c53feeb5be7b1dda59397b7f20b">

<td class="memItemLeft" align="right" valign="top">bool </td>

<td class="memItemRight" valign="bottom">[hasTag](classXMLTag.html#a97755c53feeb5be7b1dda59397b7f20b) (const char *szTagName) const</td>

</tr>

<tr class="memitem:a35f41ff597a370a490f9f630a5fd9bbf">

<td class="memItemLeft" align="right" valign="top">bool </td>

<td class="memItemRight" valign="bottom">[hasTag](classXMLTag.html#a35f41ff597a370a490f9f630a5fd9bbf) (const std::string strTagName) const</td>

</tr>

<tr class="memitem:aa009d55c84b39b8bce0cfebfa2981168">

<td class="memItemLeft" align="right" valign="top"><a class="anchor" id="aa009d55c84b39b8bce0cfebfa2981168"></a>bool </td>

<td class="memItemRight" valign="bottom">**deleteTag** (std::string strName)</td>

</tr>

<tr class="memitem:ad1abf3fc32477c2376fda4138644fd00">

<td class="memItemLeft" align="right" valign="top"><a class="anchor" id="ad1abf3fc32477c2376fda4138644fd00"></a>bool </td>

<td class="memItemRight" valign="bottom">**deleteTag** (const char *szName)</td>

</tr>

<tr class="memitem:aa68564c3cf2dc2d0bf7672323ca79d61">

<td class="memItemLeft" align="right" valign="top">const std::string & </td>

<td class="memItemRight" valign="bottom">[value](classXMLTag.html#aa68564c3cf2dc2d0bf7672323ca79d61) () const</td>

</tr>

<tr class="memitem:adf8a5b94085d94caffd8e2ac6f9ccd50">

<td class="memItemLeft" align="right" valign="top">int </td>

<td class="memItemRight" valign="bottom">[intValue](classXMLTag.html#adf8a5b94085d94caffd8e2ac6f9ccd50) () const</td>

</tr>

<tr class="memitem:a724a3f0ac76f19dff3d358b0ad6cbfd8">

<td class="memItemLeft" align="right" valign="top">float </td>

<td class="memItemRight" valign="bottom">[floatValue](classXMLTag.html#a724a3f0ac76f19dff3d358b0ad6cbfd8) () const</td>

</tr>

<tr class="memitem:abee6a95c46d7d617bc43fd27f85b04ea">

<td class="memItemLeft" align="right" valign="top">bool </td>

<td class="memItemRight" valign="bottom">[boolValue](classXMLTag.html#abee6a95c46d7d617bc43fd27f85b04ea) () const</td>

</tr>

<tr class="memitem:ad18250a0e8a8795df5d0eecef94db245">

<td class="memItemLeft" align="right" valign="top">void </td>

<td class="memItemRight" valign="bottom">[setValue](classXMLTag.html#ad18250a0e8a8795df5d0eecef94db245) (const char *szValue)</td>

</tr>

<tr class="memitem:aeb2b46509fd1ef709da934da3720b49b">

<td class="memItemLeft" align="right" valign="top">void </td>

<td class="memItemRight" valign="bottom">[setValue](classXMLTag.html#aeb2b46509fd1ef709da934da3720b49b) (std::string strValue)</td>

</tr>

<tr class="memitem:acf8f953bc884e514280be77bd277ec19">

<td class="memItemLeft" align="right" valign="top">void </td>

<td class="memItemRight" valign="bottom">[setValue](classXMLTag.html#acf8f953bc884e514280be77bd277ec19) (int iValue)</td>

</tr>

<tr class="memitem:a875cb4917c8ddd410e67bdc788af4a1b">

<td class="memItemLeft" align="right" valign="top">void </td>

<td class="memItemRight" valign="bottom">[setValue](classXMLTag.html#a875cb4917c8ddd410e67bdc788af4a1b) (unsigned int uiValue)</td>

</tr>

<tr class="memitem:a32d81071e3d086e94c0bf9f647574253">

<td class="memItemLeft" align="right" valign="top">void </td>

<td class="memItemRight" valign="bottom">[setValue](classXMLTag.html#a32d81071e3d086e94c0bf9f647574253) (float fValue)</td>

</tr>

<tr class="memitem:ae51601f87d6623d2e47a5d9e352b6d32">

<td class="memItemLeft" align="right" valign="top">void </td>

<td class="memItemRight" valign="bottom">[setValue](classXMLTag.html#ae51601f87d6623d2e47a5d9e352b6d32) (double dValue)</td>

</tr>

<tr class="memitem:ac1f9e996bd4a053d3c59542852af27ee">

<td class="memItemLeft" align="right" valign="top">const std::string & </td>

<td class="memItemRight" valign="bottom">[name](classXMLTag.html#ac1f9e996bd4a053d3c59542852af27ee) () const</td>

</tr>

<tr class="memitem:ab47cb5e0115930055afeda8cbda63ee1">

<td class="memItemLeft" align="right" valign="top">void </td>

<td class="memItemRight" valign="bottom">[setName](classXMLTag.html#ab47cb5e0115930055afeda8cbda63ee1) (const char *szTagName)</td>

</tr>

<tr class="memitem:a297c5f691720e1d62b6589ec917c2f00">

<td class="memItemLeft" align="right" valign="top">void </td>

<td class="memItemRight" valign="bottom">[setName](classXMLTag.html#a297c5f691720e1d62b6589ec917c2f00) (std::string strTagName)</td>

</tr>

<tr class="memitem:ab1583e341298c05a4f378121098f46a5">

<td class="memItemLeft" align="right" valign="top">const std::string & </td>

<td class="memItemRight" valign="bottom">[attribute_name](classXMLTag.html#ab1583e341298c05a4f378121098f46a5) (int iAttibute) const</td>

</tr>

<tr class="memitem:a5d3e87e0e70f3b12d9a74f4d658ec42a">

<td class="memItemLeft" align="right" valign="top">int </td>

<td class="memItemRight" valign="bottom">[intAttribute](classXMLTag.html#a5d3e87e0e70f3b12d9a74f4d658ec42a) (std::string szAttribute) const</td>

</tr>

<tr class="memitem:ade74eef8d9ec7c3a9b8745b7aa6af95e">

<td class="memItemLeft" align="right" valign="top">bool </td>

<td class="memItemRight" valign="bottom">[boolAttribute](classXMLTag.html#ade74eef8d9ec7c3a9b8745b7aa6af95e) (const char *szAttribute) const</td>

</tr>

<tr class="memitem:a1c130d5b474f45a815966b16bcf0a257">

<td class="memItemLeft" align="right" valign="top">const std::string & </td>

<td class="memItemRight" valign="bottom">[attribute](classXMLTag.html#a1c130d5b474f45a815966b16bcf0a257) (int iAttribute) const</td>

</tr>

<tr class="memitem:a07e3f34c28d10daf1c40ade8e6b13882">

<td class="memItemLeft" align="right" valign="top">const std::string & </td>

<td class="memItemRight" valign="bottom">[attribute](classXMLTag.html#a07e3f34c28d10daf1c40ade8e6b13882) (std::string szAttribute) const</td>

</tr>

<tr class="memitem:a419e21a7a2b4247e122c35bdb2f72e59">

<td class="memItemLeft" align="right" valign="top">bool </td>

<td class="memItemRight" valign="bottom">[hasAttribute](classXMLTag.html#a419e21a7a2b4247e122c35bdb2f72e59) (const char *szAttribute) const</td>

</tr>

<tr class="memitem:a7c9f4180ceaaece9d8a2d34e5ece30f0">

<td class="memItemLeft" align="right" valign="top">void </td>

<td class="memItemRight" valign="bottom">[setAttribute](classXMLTag.html#a7c9f4180ceaaece9d8a2d34e5ece30f0) (const char *szAttribute, const char *szValue)</td>

</tr>

<tr class="memitem:aaf2a8c2b8297fc284d694c2c961eb7c3">

<td class="memItemLeft" align="right" valign="top">void </td>

<td class="memItemRight" valign="bottom">[setAttribute](classXMLTag.html#aaf2a8c2b8297fc284d694c2c961eb7c3) (const char *szAttribute, int [intValue](classXMLTag.html#adf8a5b94085d94caffd8e2ac6f9ccd50))</td>

</tr>

<tr class="memitem:a760f7094b052cec41144cdabfc793dcb">

<td class="memItemLeft" align="right" valign="top">void </td>

<td class="memItemRight" valign="bottom">[setAttribute](classXMLTag.html#a760f7094b052cec41144cdabfc793dcb) (std::string strAttribute, std::string strValue)</td>

</tr>

<tr class="memitem:a0e7db2b9aa1f66246ac566aa67f1612e">

<td class="memItemLeft" align="right" valign="top">bool </td>

<td class="memItemRight" valign="bottom">[incomplete](classXMLTag.html#a0e7db2b9aa1f66246ac566aa67f1612e) ()</td>

</tr>

</tbody>

</table>

## Constructor & Destructor Documentation

<a class="anchor" id="a07b7b572924c89d1db43babe1186549e"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">XMLTag::XMLTag</td>

<td>(</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Default constructor

</div>

</div>

<a class="anchor" id="a9b237be00020a99ce884c31375786560"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">XMLTag::XMLTag</td>

<td>(</td>

<td class="paramtype">const [XMLTag](classXMLTag.html) & </td>

<td class="paramname">_tag_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Copy Constructor

</div>

</div>

<a class="anchor" id="a9b4ce2949388da7115747db4244d6332"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">XMLTag::XMLTag</td>

<td>(</td>

<td class="paramtype">[XMLTag](classXMLTag.html) * </td>

<td class="paramname">_pParent_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Constructor

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">pParent</td>

<td>Mainly for internal use; pointer to parent tag containing this tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="a5a7448a382d37ae1f8b1e53a1536c25e"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">XMLTag::XMLTag</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szTagName_,</td>

</tr>

<tr>

<td class="paramtype">const char * </td>

<td class="paramname">_szValue_ </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Constructor

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szTagName</td>

<td>Name of a contructed tag</td>

</tr>

<tr>

<td class="paramname">szValue</td>

<td>Value of a constructed tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="a155b50e71dc71e9174de681a06307d72"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">XMLTag::XMLTag</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szTagName_,</td>

</tr>

<tr>

<td class="paramtype">bool </td>

<td class="paramname">_bValue_ </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Constructor

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szTagName</td>

<td>Name of a contructed tag</td>

</tr>

<tr>

<td class="paramname">bValue</td>

<td>Value of a constructed tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="a06d4c7e7d1c04e2d81f592340ba2ae9d"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">XMLTag::XMLTag</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szTagName_,</td>

</tr>

<tr>

<td class="paramtype">int </td>

<td class="paramname">_intValue_ </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Constructor

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szTagName</td>

<td>Name of a contructed tag</td>

</tr>

<tr>

<td class="paramname">intValue</td>

<td>Value of a constructed tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="aa3e495579da8cb5108632de3f91ced9b"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">XMLTag::XMLTag</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szTagName_,</td>

</tr>

<tr>

<td class="paramtype">unsigned int </td>

<td class="paramname">_uintValue_ </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Constructor

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szTagName</td>

<td>Name of a contructed tag</td>

</tr>

<tr>

<td class="paramname">uintValue</td>

<td>Value of a constructed tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="aba42746b9a1afb48102927dade6b4b98"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">XMLTag::XMLTag</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szTagName_,</td>

</tr>

<tr>

<td class="paramtype">float </td>

<td class="paramname">_floatValue_ </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Constructor

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szTagName</td>

<td>Name of a contructed tag</td>

</tr>

<tr>

<td class="paramname">uintValue</td>

<td>Value of a constructed tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="a6ca10fbcba355ea0d9c575c9cbf36c0d"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">XMLTag::XMLTag</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szTagName_,</td>

</tr>

<tr>

<td class="paramtype">double </td>

<td class="paramname">_doubleValue_ </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Constructor

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szTagName</td>

<td>Name of a contructed tag</td>

</tr>

<tr>

<td class="paramname">uintValue</td>

<td>Value of a constructed tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="a42668f01feefc6e0191348aa08f13b84"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">XMLTag::XMLTag</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szTagName_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Constructor

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szTagName</td>

<td>Name of a constructed tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="a9798eccc00847c1b34e3c7a4a819d649"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">XMLTag::XMLTag</td>

<td>(</td>

<td class="paramtype">std::string </td>

<td class="paramname">_strTagName_,</td>

</tr>

<tr>

<td class="paramtype">std::string </td>

<td class="paramname">_strValue_ = `""` </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Constructor

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">strTagName</td>

<td>std::string input for tag name</td>

</tr>

<tr>

<td class="paramname">strValue</td>

<td>std::string input for tag value</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="a2d329848ea05b546c994bb2204ab349e"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">XMLTag::~XMLTag</td>

<td>(</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Destructor

</div>

</div>

## Member Function Documentation

<a class="anchor" id="a41dcf7fe1eb3058bd81930233dee8d28"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">[XMLTag](classXMLTag.html) & XMLTag::addTag</td>

<td>(</td>

<td class="paramtype">[XMLTag](classXMLTag.html) * </td>

<td class="paramname">_pTag_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Added a child to this tag.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">Tag</td>

<td>XMLTag*</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>Returns a reference to the child tag stored.</dd>

</dl>

</div>

</div>

<a class="anchor" id="ac284b24a802583ac9ceb358125e178bf"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">[XMLTag](classXMLTag.html) & XMLTag::addTag</td>

<td>(</td>

<td class="paramtype">[XMLTag](classXMLTag.html) & </td>

<td class="paramname">_Tag_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Added a child to this tag.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">Tag</td>

<td>[XMLTag](classXMLTag.html)</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>Returns a reference to the child tag stored.</dd>

</dl>

</div>

</div>

<a class="anchor" id="a2bb81bc008ea18c0a4a6606a824133eb"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">[XMLTag](classXMLTag.html) & XMLTag::addTag</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szName_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Added a child to this tag.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szName</td>

<td>- name of new child tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>Returns a refernce to the child tag stored.</dd>

</dl>

</div>

</div>

<a class="anchor" id="a972545b8238d250185c7552f9285a592"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">[XMLTag](classXMLTag.html) & XMLTag::addTag</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szName_,</td>

</tr>

<tr>

<td class="paramtype">const char * </td>

<td class="paramname">_szValue_ </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Added a child to this tag.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szName</td>

<td>- name of new child tag</td>

</tr>

<tr>

<td class="paramname">szValue</td>

<td>- Value of new child tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>Returns a refernce to the child tag stored.</dd>

</dl>

</div>

</div>

<a class="anchor" id="aec264a9f4306d5b90c097c7f1d088283"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">[XMLTag](classXMLTag.html) & XMLTag::addTag</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szName_,</td>

</tr>

<tr>

<td class="paramtype">bool </td>

<td class="paramname">_bValue_ </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Added a child to this tag.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szName</td>

<td>- name of new child tag</td>

</tr>

<tr>

<td class="paramname">bValue</td>

<td>- Value of new child tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>Returns a refernce to the child tag stored.</dd>

</dl>

</div>

</div>

<a class="anchor" id="a836724f95250e0e46cb1c4900aebf655"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">[XMLTag](classXMLTag.html) & XMLTag::addTag</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szName_,</td>

</tr>

<tr>

<td class="paramtype">int </td>

<td class="paramname">_intValue_ </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Added a child to this tag.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szName</td>

<td>- name of new child tag</td>

</tr>

<tr>

<td class="paramname">intValue</td>

<td>- Value of new child tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>Returns a refernce to the child tag stored.</dd>

</dl>

</div>

</div>

<a class="anchor" id="a4c7ee78fd9f69fa4d617eee81538f174"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">[XMLTag](classXMLTag.html) & XMLTag::addTag</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szName_,</td>

</tr>

<tr>

<td class="paramtype">unsigned int </td>

<td class="paramname">_uintValue_ </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Added a child to this tag.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szName</td>

<td>- name of new child tag</td>

</tr>

<tr>

<td class="paramname">uintValue</td>

<td>- Value of new child tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>Returns a refernce to the child tag stored.</dd>

</dl>

</div>

</div>

<a class="anchor" id="ab114ea4189652208334bdbf803494e6c"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">[XMLTag](classXMLTag.html) & XMLTag::addTag</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szName_,</td>

</tr>

<tr>

<td class="paramtype">float </td>

<td class="paramname">_floatValue_ </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Added a child to this tag.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szName</td>

<td>- name of new child tag</td>

</tr>

<tr>

<td class="paramname">floatValue</td>

<td>- Value of new child tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>Returns a refernce to the child tag stored.</dd>

</dl>

</div>

</div>

<a class="anchor" id="a06ed9de698dc3c7d9c6bfd5acdcddff0"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">[XMLTag](classXMLTag.html) & XMLTag::addTag</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szName_,</td>

</tr>

<tr>

<td class="paramtype">double </td>

<td class="paramname">_doubleValue_ </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Added a child to this tag.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szName</td>

<td>- name of new child tag</td>

</tr>

<tr>

<td class="paramname">doubleValue</td>

<td>- Value of new child tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>Returns a refernce to the child tag stored.</dd>

</dl>

</div>

</div>

<a class="anchor" id="a24e64fb58c0aa2680a19dba6c2dacb7d"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">[XMLTag](classXMLTag.html) & XMLTag::addTag</td>

<td>(</td>

<td class="paramtype">std::string </td>

<td class="paramname">_strName_,</td>

</tr>

<tr>

<td class="paramtype">std::string </td>

<td class="paramname">_strValue_ = `""` </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Added a child to this tag.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">strName</td>

<td>- name of new child tag</td>

</tr>

<tr>

<td class="paramname">strValue=""</td>

<td>- Value of new child tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>Returns a refernce to the child tag stored.</dd>

</dl>

</div>

</div>

<a class="anchor" id="a17ff3c7cfda65706f7b3655f68a2ddda"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">[XMLTag](classXMLTag.html) & XMLTag::addXML</td>

<td>(</td>

<td class="paramtype">std::string </td>

<td class="paramname">_strXML_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Added a child to this tag that contain the XML in the strXML param. Use insertXML for multiple XML tags non-nested

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">Tag</td>

<td>std::string (or a char *)</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>Returns a refernce to the child tag stored.</dd>

</dl>

</div>

</div>

<a class="anchor" id="a1c130d5b474f45a815966b16bcf0a257"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">const std::string & XMLTag::attribute</td>

<td>(</td>

<td class="paramtype">int </td>

<td class="paramname">_iAttribute_</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Returns the value of an attribute of this tag.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">iAttribute</td>

<td>int value used for iterating through all attributes unknown or otherwise.</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>std::string</dd>

</dl>

</div>

</div>

<a class="anchor" id="a07e3f34c28d10daf1c40ade8e6b13882"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">const std::string & XMLTag::attribute</td>

<td>(</td>

<td class="paramtype">std::string </td>

<td class="paramname">_szAttribute_</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Returns the value of an attribute of this tag.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szAttribute</td>

<td>const char* to the name of the attribute</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>std::string</dd>

</dl>

</div>

</div>

<a class="anchor" id="aedf362ddaed5f3fac2f6686ccc742913"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">int XMLTag::attribute_count</td>

<td>(</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Returns the number of attributes for this tag.

<dl class="section return">

<dt>Returns</dt>

<dd>int count of attributes</dd>

</dl>

</div>

</div>

<a class="anchor" id="ab1583e341298c05a4f378121098f46a5"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">const std::string & XMLTag::attribute_name</td>

<td>(</td>

<td class="paramtype">int </td>

<td class="paramname">_iAttibute_</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Returns the name of an attribute of this tag.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">iAttribute</td>

<td>int value used for iterating through all attributes unknown or otherwise.</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>std::string</dd>

</dl>

</div>

</div>

<a class="anchor" id="ade74eef8d9ec7c3a9b8745b7aa6af95e"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">bool XMLTag::boolAttribute</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szAttribute_</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Returns the boolean value of an attribute of this tag.

Returns the bool value assigned to this tag. Comparison is always case insenitive.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szAttribute</td>

<td>name of attribute</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>Returns true if value equals On, True, Hi, High, Yes, and any number other than zero. Returns false for anything else</dd>

</dl>

</div>

</div>

<a class="anchor" id="abee6a95c46d7d617bc43fd27f85b04ea"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">bool XMLTag::boolValue</td>

<td>(</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Returns the bool value assigned to this tag. Comparison is always case insenitive.

<dl class="section return">

<dt>Returns</dt>

<dd>Returns true if value equals On, True, Hi, High, Yes, and any number other than zero. Returns false for anything else</dd>

</dl>

</div>

</div>

<a class="anchor" id="ab9701b23aadda012638dee320f9372f0"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">const char* XMLTag::buffer</td>

<td>(</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Returns a pointer to the null terminated buffer used internally to parse the XML.

<dl class="section return">

<dt>Returns</dt>

<dd>const char* to the buffer</dd>

</dl>

</div>

</div>

<a class="anchor" id="a937640876c42ca652f488336d1b1b30b"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">int XMLTag::buffer_size</td>

<td>(</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Returns the size in bytes of buffer used internally to parse the XML.

<dl class="section return">

<dt>Returns</dt>

<dd>int size of internal buffer</dd>

</dl>

</div>

</div>

<a class="anchor" id="a3c5a59da18f60c57c225695ca918cb08"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">[XMLTag](classXMLTag.html) & XMLTag::buildPath</td>

<td>(</td>

<td class="paramtype">const std::string </td>

<td class="paramname">_strTagPath_,</td>

</tr>

<tr>

<td class="paramname">_..._ </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

returns the path relative to the main known parent of the node

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">strTagPath</td>

<td>- relative path of tag to create NOTE: '#' place markers are use to indicate additional counter args (ie, path( "first/#/item/create", i ).setValue("Hello"); )</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>[XMLTag](classXMLTag.html)&</dd>

</dl>

</div>

</div>

<a class="anchor" id="a89d6e565a1e3f0431d5ef045b78e66bb"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">void XMLTag::clear</td>

<td>(</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Clears the name, value, all attributes, and all children of this tag

</div>

</div>

<a class="anchor" id="a4c71240412e01900fd89453ace812350"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">int XMLTag::count</td>

<td>(</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Returns the number of child tag in this tag.

<dl class="section return">

<dt>Returns</dt>

<dd>int count of children</dd>

</dl>

</div>

</div>

<a class="anchor" id="a724a3f0ac76f19dff3d358b0ad6cbfd8"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">float XMLTag::floatValue</td>

<td>(</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Returns the floating point value assigned to this tag. Calls atof internally.

<dl class="section return">

<dt>Returns</dt>

<dd>returns a float.</dd>

</dl>

</div>

</div>

<a class="anchor" id="a5f6f0a8ce4b6ed80aa45d5d02c3d28a6"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">const char * XMLTag::getXML</td>

<td>(</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Returns a pointer to a NULL terminated string containing XML dynamically generated by this instance. The class manages

<dl class="section return">

<dt>Returns</dt>

<dd>const char* - returns a pointer to an interal dynamically generated buffer of XML that represents what this object contains</dd>

</dl>

</div>

</div>

<a class="anchor" id="ab435f16a4863605952d447f000e8e551"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">const char * XMLTag::getXMLFormatted</td>

<td>(</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Returns a pointer to a NULL terminated string containing formatted XML dynamically generated by this instance. The class manages

<dl class="section return">

<dt>Returns</dt>

<dd>const char* - returns a pointer to an interal dynamically generated buffer of XML that represents what this object contains</dd>

</dl>

</div>

</div>

<a class="anchor" id="a419e21a7a2b4247e122c35bdb2f72e59"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">bool XMLTag::hasAttribute</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szAttribute_</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Returns true if attribute name is present for this tag.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szAttribute</td>

<td>const char* to the name of the attribute</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>bool</dd>

</dl>

</div>

</div>

<a class="anchor" id="a37cca22a82e36cc5c62ca78a159b3d58"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">bool XMLTag::hasPath</td>

<td>(</td>

<td class="paramtype">const std::string </td>

<td class="paramname">_strTagPath_,</td>

</tr>

<tr>

<td class="paramname">_..._ </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

returns true if the path relative to the main known parent of the node exists

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">strTagPath</td>

<td>- relative path of tag to obtain NOTE: '#' place markers are use to indicate additional counter args (ie, path( "first/#/item/#", i, j ) )</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>[XMLTag](classXMLTag.html)&</dd>

</dl>

</div>

</div>

<a class="anchor" id="a97755c53feeb5be7b1dda59397b7f20b"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">bool XMLTag::hasTag</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szTagName_</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Returns true if tag name is present inside this tag.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szTagName</td>

<td>const char* to the name of the tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>bool</dd>

</dl>

</div>

</div>

<a class="anchor" id="a35f41ff597a370a490f9f630a5fd9bbf"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">bool XMLTag::hasTag</td>

<td>(</td>

<td class="paramtype">const std::string </td>

<td class="paramname">_strTagName_</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Returns true if tag name is present inside this tag.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">strTagName</td>

<td>std::string of the name of the tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>bool</dd>

</dl>

</div>

</div>

<a class="anchor" id="adab99b26b6d5687e32182367f8e11aa3"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">void XMLTag::ignoreCase</td>

<td>(</td>

<td class="paramtype">bool </td>

<td class="paramname">_bIgnore_ = `false`</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

When set to true this method tells the parser to force all tag names and attribute name to lowercase. All access function that except names force all passed in name to lowercase to insure case insensitive access.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">bIgnore</td>

<td>bool - true activates case insensitivity</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="a0e7db2b9aa1f66246ac566aa67f1612e"></a>

<div class="memitem">

<div class="memproto">

<table class="mlabels">

<tbody>

<tr>

<td class="mlabels-left">

<table class="memname">

<tbody>

<tr>

<td class="memname">bool XMLTag::incomplete</td>

<td>(</td>

<td>)</td>

</tr>

</tbody>

</table>

</td>

<td class="mlabels-right"><span class="mlabels"><span class="mlabel">inline</span></span></td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Returns true if internal XML buffer is known to be incomplete.

<dl class="section return">

<dt>Returns</dt>

<dd>bool</dd>

</dl>

</div>

</div>

<a class="anchor" id="a60c9450d76565907814f6331875aeeaa"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">void XMLTag::insertXML</td>

<td>(</td>

<td class="paramtype">std::string </td>

<td class="paramname">_strXML_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Added one or more child tags to this tag that contain the XML in the strXML param.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">strXML</td>

<td>std::string (or a char *)</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>void</dd>

</dl>

</div>

</div>

<a class="anchor" id="a5d3e87e0e70f3b12d9a74f4d658ec42a"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">int XMLTag::intAttribute</td>

<td>(</td>

<td class="paramtype">std::string </td>

<td class="paramname">_szAttribute_</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Returns the interger value of an attribute of this tag.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szAttribute</td>

<td>name of attribute</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>int - value returned by atoi()</dd>

</dl>

</div>

</div>

<a class="anchor" id="adf8a5b94085d94caffd8e2ac6f9ccd50"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">int XMLTag::intValue</td>

<td>(</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Returns the integer value assigned to this tag. Calls atoi internally.

<dl class="section return">

<dt>Returns</dt>

<dd>returns an integer.</dd>

</dl>

</div>

</div>

<a class="anchor" id="ab0da977fa0d937a402299a77c2d70b22"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">bool XMLTag::load</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szFileName_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Loads an XML file to be parsed.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szFileName</td>

<td>const char pointer to a filename</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>bool - returns false if the file could not be found or loaded.</dd>

</dl>

</div>

</div>

<a class="anchor" id="ac1f9e996bd4a053d3c59542852af27ee"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">const std::string & XMLTag::name</td>

<td>(</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Returns the name of this tag

<dl class="section return">

<dt>Returns</dt>

<dd>returns a std::string to allow easy use of its '==' comparison operator.</dd>

</dl>

</div>

</div>

<a class="anchor" id="ae6e264eb5e01b4db6a688a9eeb90a257"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">bool XMLTag::operator!=</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szComp_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

This too, is a debatable operator: Should it compare name or value? It currently compares to its value if it has one. If there is no value it compares to the name.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szComp</td>

<td>const char * szComp</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>bool</dd>

</dl>

</div>

</div>

<a class="anchor" id="ac7c420994cfbd7c7774446c52a43d909"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">bool XMLTag::operator!=</td>

<td>(</td>

<td class="paramtype">[XMLTag](classXMLTag.html) & </td>

<td class="paramname">_tag_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

This calls operator==( XMLTag &tag ) logically inverted.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">tag</td>

<td>const [XMLTag](classXMLTag.html) &tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>bool</dd>

</dl>

</div>

</div>

<a class="anchor" id="a122a7d4eac94eeab7eb7722ecb283b88"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">[XMLTag](classXMLTag.html) & XMLTag::operator=</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szComp_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Assigns a value to a tag.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szComp</td>

<td>const char * szComp</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>bool</dd>

</dl>

</div>

</div>

<a class="anchor" id="a24fed9521a79d4047d8aa658196e02aa"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">[XMLTag](classXMLTag.html) & XMLTag::operator=</td>

<td>(</td>

<td class="paramtype">const [XMLTag](classXMLTag.html) & </td>

<td class="paramname">_tag_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Assigns the content of the tag reference passed in.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">tag</td>

<td>[XMLTag](classXMLTag.html)&</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>bool</dd>

</dl>

</div>

</div>

<a class="anchor" id="a25d6027ae84f0fba22aaea88c92cc21f"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">bool XMLTag::operator==</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szComp_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

This is a debatable operator: Should it compare name or value? It currently compares its value if it has one. If there is no value it compares the name.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szComp</td>

<td>const char * szComp</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>bool</dd>

</dl>

</div>

</div>

<a class="anchor" id="a6400cc4f6932df2245f036db79922004"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">bool XMLTag::operator==</td>

<td>(</td>

<td class="paramtype">const [XMLTag](classXMLTag.html) & </td>

<td class="paramname">_tag_</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

This recursively compares the names and values of the tags and attribute of an [XMLTag](classXMLTag.html) instance to this one.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">tag</td>

<td>const [XMLTag](classXMLTag.html) &tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>bool</dd>

</dl>

</div>

</div>

<a class="anchor" id="a65bbf831deac7cce44a3dc40d1487413"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">[XMLTag](classXMLTag.html) & XMLTag::operator[]</td>

<td>(</td>

<td class="paramtype">const std::string </td>

<td class="paramname">_strTagName_</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Index operator; provides access to a child tag by name. If a tag contains multiple children of the same name (which is common in XML) the first child with that name is returned.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szTagName</td>

<td>const std::string with name of child tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>Returns a reference to the requested child tag. If the tag does not exist, it returns a reference to an internal bogus tag to prevent applications from crashing.

<pre class="fragment">      A "strictness" flag will be added later to cause
      the class to throw an exception if a tag is
      requested that is not present.</pre>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="a0b7f3b781d80c25e04adc4d95591bb4d"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">[XMLTag](classXMLTag.html) & XMLTag::operator[]</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szTagName_</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Index operator; provides access to a child tag by name. If a tag contains multiple children of the same name (which is common in XML) the first child with that name is returned.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szTagName</td>

<td>const char* pointer to name of child tag</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>Returns a reference to the requested child tag. If the tag does not exist, it returns a reference to an internal bogus tag to prevent applications from crashing.

<pre class="fragment">      A "strictness" flag will be added later to cause
      the class to throw an exception if a tag is
      requested that is not present.</pre>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="a4530706e668da47085b454d6402bc190"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">[XMLTag](classXMLTag.html) & XMLTag::operator[]</td>

<td>(</td>

<td class="paramtype">size_t </td>

<td class="paramname">_iTagIndex_</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Index operator; provides access to a child tag by index position. This is useful for tags that contain multiple tag entries of the same name. When a tag name or specification is unknown this method will be the only way to access a tag a discover its details.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">iTagIndex</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>Returns a reference to the requested child tag. If the index goes out of bounds, it returns a reference to an internal bogus tag to prevent applications from crashing.

<pre class="fragment">      A "strictness" flag will be added later to cause the
      class to throw an exception if a tag is requested
      that is not present.</pre>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="aef2014a418d40d88ce2751f2badaec42"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">[XMLTag](classXMLTag.html) * XMLTag::parent</td>

<td>(</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Returns a pointer to the parent tag. Used internally for tag reference depth.

<dl class="section return">

<dt>Returns</dt>

<dd>[XMLTag](classXMLTag.html) pointer</dd>

</dl>

</div>

</div>

<a class="anchor" id="abc5bb4a3418883769b75fc6b8fac1b69"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">const std::string XMLTag::path</td>

<td>(</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

returns the path relative to the main known parent of the node

<dl class="section return">

<dt>Returns</dt>

<dd>std::string</dd>

</dl>

</div>

</div>

<a class="anchor" id="ada73a34c65c85a2d271b11c73ce98ffa"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">[XMLTag](classXMLTag.html) & XMLTag::path</td>

<td>(</td>

<td class="paramtype">const std::string </td>

<td class="paramname">_strTagPath_,</td>

</tr>

<tr>

<td class="paramtype">std::vector< int > </td>

<td class="paramname">_vecVals_ </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

returns the path relative to the main known parent of the node

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">strTagPath</td>

<td>- relative path of tag to obtain NOTE: '#' place markers are use to indicate additional counter args (ie, path( "first/#/item", vec ).[value()](classXMLTag.html#aa68564c3cf2dc2d0bf7672323ca79d61) )</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>[XMLTag](classXMLTag.html)&</dd>

</dl>

</div>

</div>

<a class="anchor" id="aba83691a33252ae5338d4ad649396146"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">[XMLTag](classXMLTag.html) & XMLTag::path</td>

<td>(</td>

<td class="paramtype">const std::string </td>

<td class="paramname">_strTagPath_,</td>

</tr>

<tr>

<td class="paramname">_..._ </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

returns the path relative to the main known parent of the node

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">strTagPath</td>

<td>- relative path of tag to obtain NOTE: '#' place markers are use to indicate additional counter args (ie, path( "first/#/item/#", i, j ).[value()](classXMLTag.html#aa68564c3cf2dc2d0bf7672323ca79d61) )</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>[XMLTag](classXMLTag.html)&</dd>

</dl>

</div>

</div>

<a class="anchor" id="a66a342b912dd779f6afb5147cbf25073"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">int XMLTag::read</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_pBuffer_,</td>

</tr>

<tr>

<td class="paramtype">int </td>

<td class="paramname">_iBufferSize_ = `0` </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

reads XML for parsing from a buffer pointer

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">pBuffer</td>

<td>const char pointer to buffer to parse.</td>

</tr>

<tr>

<td class="paramname">iBufferSize</td>

<td>size in in chars of buffer to parse</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>bool - true of successful</dd>

</dl>

</div>

</div>

<a class="anchor" id="ae4b23a62c94695a547b0efd975d75b4d"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">bool XMLTag::read</td>

<td>(</td>

<td class="paramtype">FILE * </td>

<td class="paramname">_fp_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

reads XML for parsing from the current position of an open file pointer

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">fp</td>

<td>FILE pointer</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>bool - true of successful</dd>

</dl>

</div>

</div>

<a class="anchor" id="a7c9f4180ceaaece9d8a2d34e5ece30f0"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">void XMLTag::setAttribute</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szAttribute_,</td>

</tr>

<tr>

<td class="paramtype">const char * </td>

<td class="paramname">_szValue_ </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Sets an attribute and its value.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szAttribute</td>

<td>const char* to the attribute's name</td>

</tr>

<tr>

<td class="paramname">szValue</td>

<td>const char* to the attribute's value</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="aaf2a8c2b8297fc284d694c2c961eb7c3"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">void XMLTag::setAttribute</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szAttribute_,</td>

</tr>

<tr>

<td class="paramtype">int </td>

<td class="paramname">_intValue_ </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Sets an attribute and its value.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szAttribute</td>

<td>const char* to the attribute's name</td>

</tr>

<tr>

<td class="paramname">intValue</td>

<td>- the attribute's int value</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="a760f7094b052cec41144cdabfc793dcb"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">void XMLTag::setAttribute</td>

<td>(</td>

<td class="paramtype">std::string </td>

<td class="paramname">_strAttribute_,</td>

</tr>

<tr>

<td class="paramtype">std::string </td>

<td class="paramname">_strValue_ </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Sets an attribute and its value.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">strAttribute</td>

<td>std::string of attribute's name</td>

</tr>

<tr>

<td class="paramname">strValue</td>

<td>std::string of attribute's value</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="ab47cb5e0115930055afeda8cbda63ee1"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">void XMLTag::setName</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szTagName_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Sets the name of this tag to the contents of the char pointer passed in.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szTagName</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="a297c5f691720e1d62b6589ec917c2f00"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">void XMLTag::setName</td>

<td>(</td>

<td class="paramtype">std::string </td>

<td class="paramname">_strTagName_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Sets the value of this tag to the contents of the std::string passed in.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">strValue</td>

<td>std::string</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="ad18250a0e8a8795df5d0eecef94db245"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">void XMLTag::setValue</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szValue_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Sets the value of this tag to the contents of the char pointer passed in.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szValue</td>

<td>const char</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="aeb2b46509fd1ef709da934da3720b49b"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">void XMLTag::setValue</td>

<td>(</td>

<td class="paramtype">std::string </td>

<td class="paramname">_strValue_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Sets the value of this tag to the contents of std::string passed in.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szValue</td>

<td>std::string</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="acf8f953bc884e514280be77bd277ec19"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">void XMLTag::setValue</td>

<td>(</td>

<td class="paramtype">int </td>

<td class="paramname">_iValue_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Sets the value of this tag to the contents of the int passed in.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">iValue</td>

<td>int</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="a875cb4917c8ddd410e67bdc788af4a1b"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">void XMLTag::setValue</td>

<td>(</td>

<td class="paramtype">unsigned int </td>

<td class="paramname">_uiValue_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Sets the value of this tag to the contents of unsigned int passed in.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">uiValue</td>

<td>unsigned int</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="a32d81071e3d086e94c0bf9f647574253"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">void XMLTag::setValue</td>

<td>(</td>

<td class="paramtype">float </td>

<td class="paramname">_fValue_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Sets the value of this tag to the contents of the float passed in.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">fValue</td>

<td>unsigned int</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="ae51601f87d6623d2e47a5d9e352b6d32"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">void XMLTag::setValue</td>

<td>(</td>

<td class="paramtype">double </td>

<td class="paramname">_dValue_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Sets the value of this tag to the contents of the float passed in.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">fValue</td>

<td>unsigned int</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="a4f28e36b5c33620f60e5c513b5fb9c09"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">bool XMLTag::store</td>

<td>(</td>

<td class="paramtype">const char * </td>

<td class="paramname">_szFileName_,</td>

</tr>

<tr>

<td class="paramtype">bool </td>

<td class="paramname">_bFormatted_ = `false` </td>

</tr>

<tr>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

This method will writes out the structure of tag objects in XML to a file. If the file exists it is overwritten.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">szFileName</td>

<td>const char pointer to a file name</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>bool - true if successful</dd>

</dl>

</div>

</div>

<a class="anchor" id="aa6a58dea096f497f7cac715d66ac0424"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">void XMLTag::strictMode</td>

<td>(</td>

<td class="paramtype">bool </td>

<td class="paramname">_bMode_</td>

<td>)</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

By default access to tags or attibutes that do not exist return blank to prevent memory access violations. When bMode is set to true, an exception is thrown containing details about the access violation.

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">bMode</td>

<td>bool - true activates strict mode</td>

</tr>

</tbody>

</table>

</dd>

</dl>

</div>

</div>

<a class="anchor" id="aa68564c3cf2dc2d0bf7672323ca79d61"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">const std::string & XMLTag::value</td>

<td>(</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Returns the value assigned to this tag

<dl class="section return">

<dt>Returns</dt>

<dd>returns a std::string to allow easy use of its '==' comparison operator.</dd>

</dl>

</div>

</div>

<a class="anchor" id="a718b299712d12f38592bae89c52b9970"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">int XMLTag::write</td>

<td>(</td>

<td class="paramtype">FILE * </td>

<td class="paramname">_fp_</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Writes XML dynamically generated by this instance to an open file descriptor and leaves it open

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">fp</td>

<td>FILE pointer</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>int - number of bytes written</dd>

</dl>

</div>

</div>

<a class="anchor" id="a135670a13b5edc97e0938a17bccd7cd9"></a>

<div class="memitem">

<div class="memproto">

<table class="memname">

<tbody>

<tr>

<td class="memname">int XMLTag::write</td>

<td>(</td>

<td class="paramtype">char ** </td>

<td class="paramname">_pBuffer_</td>

<td>)</td>

<td>const</td>

</tr>

</tbody>

</table>

</div>

<div class="memdoc">

Writes XML dynamically generated by this instance to a dynamically allocated buffer.

NOTE: The buffer must be deallocated by the user with "delete[] pYourBufferPointer;"

<dl class="params">

<dt>Parameters</dt>

<dd>

<table class="params">

<tbody>

<tr>

<td class="paramname">char</td>

<td>**pBuffer - A pointer to the buffer pointer to allocate and write to</td>

</tr>

</tbody>

</table>

</dd>

</dl>

<dl class="section return">

<dt>Returns</dt>

<dd>int - number of bytes written to the buffer minus the null terminator</dd>

</dl>

</div>

</div>

* * *

The documentation for this class was generated from the following files:

*   [xmltag.h](xmltag_8h_source.html)
