#pragma checksum "/Users/bbrs.0/Projects/Second/Second/Views/Home/Deneme2.cshtml" "{ff1816ec-aa5e-4d10-87f7-6f4963833460}" "868992862ced677f4a84efd6545977e934c5ebbd"
// <auto-generated/>
#pragma warning disable 1591
[assembly: global::Microsoft.AspNetCore.Razor.Hosting.RazorCompiledItemAttribute(typeof(AspNetCore.Views_Home_Deneme2), @"mvc.1.0.view", @"/Views/Home/Deneme2.cshtml")]
namespace AspNetCore
{
    #line hidden
    using System;
    using System.Collections.Generic;
    using System.Linq;
    using System.Threading.Tasks;
    using Microsoft.AspNetCore.Mvc;
    using Microsoft.AspNetCore.Mvc.Rendering;
    using Microsoft.AspNetCore.Mvc.ViewFeatures;
#nullable restore
#line 1 "/Users/bbrs.0/Projects/Second/Second/Views/_ViewImports.cshtml"
using Second;

#line default
#line hidden
#nullable disable
#nullable restore
#line 2 "/Users/bbrs.0/Projects/Second/Second/Views/_ViewImports.cshtml"
using Second.Models;

#line default
#line hidden
#nullable disable
    [global::Microsoft.AspNetCore.Razor.Hosting.RazorSourceChecksumAttribute(@"SHA1", @"868992862ced677f4a84efd6545977e934c5ebbd", @"/Views/Home/Deneme2.cshtml")]
    [global::Microsoft.AspNetCore.Razor.Hosting.RazorSourceChecksumAttribute(@"SHA1", @"3ff2e7ef6213ca4f57ff10ad2bae37108e420c78", @"/Views/_ViewImports.cshtml")]
    public class Views_Home_Deneme2 : global::Microsoft.AspNetCore.Mvc.Razor.RazorPage<Ogrenci>
    {
        #pragma warning disable 1998
        public async override global::System.Threading.Tasks.Task ExecuteAsync()
        {
            WriteLiteral("\n<table class=\"table\">\n    <tr>\n        <th>Ad</th>\n        <th>No</th>\n    </tr>\n    <tr>\n        <td>Model.OgrAd</td>\n        <td>");
#nullable restore
#line 15 "/Users/bbrs.0/Projects/Second/Second/Views/Home/Deneme2.cshtml"
       Write(Model.OgrNo);

#line default
#line hidden
#nullable disable
            WriteLiteral("</td>\n    </tr>\n</table>\n\n<br />\n\n<h2>Bu bir ViewBag -> ");
#nullable restore
#line 21 "/Users/bbrs.0/Projects/Second/Second/Views/Home/Deneme2.cshtml"
                 Write(ViewBag.msg);

#line default
#line hidden
#nullable disable
            WriteLiteral("</h2>\n<h2>Bu bir ViewData -> ");
#nullable restore
#line 22 "/Users/bbrs.0/Projects/Second/Second/Views/Home/Deneme2.cshtml"
                  Write(ViewData["msg2"]);

#line default
#line hidden
#nullable disable
            WriteLiteral("</h2>\n<h2>Bu bir TempData -> ");
#nullable restore
#line 23 "/Users/bbrs.0/Projects/Second/Second/Views/Home/Deneme2.cshtml"
                  Write(TempData["msg3"]);

#line default
#line hidden
#nullable disable
            WriteLiteral("</h2>\n\n");
#nullable restore
#line 25 "/Users/bbrs.0/Projects/Second/Second/Views/Home/Deneme2.cshtml"
  
    string st= ViewBag.msg;
    string st2 = Convert.ToString(ViewData["msg2"]);
    string st3 = Convert.ToString(TempData["msg3"]);

#line default
#line hidden
#nullable disable
#nullable restore
#line 30 "/Users/bbrs.0/Projects/Second/Second/Views/Home/Deneme2.cshtml"
Write(st2);

#line default
#line hidden
#nullable disable
        }
        #pragma warning restore 1998
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.ViewFeatures.IModelExpressionProvider ModelExpressionProvider { get; private set; }
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.IUrlHelper Url { get; private set; }
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.IViewComponentHelper Component { get; private set; }
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.Rendering.IJsonHelper Json { get; private set; }
        [global::Microsoft.AspNetCore.Mvc.Razor.Internal.RazorInjectAttribute]
        public global::Microsoft.AspNetCore.Mvc.Rendering.IHtmlHelper<Ogrenci> Html { get; private set; }
    }
}
#pragma warning restore 1591
